#include <WiFi.h>
#include <WiFiUdp.h>

// 使用extern "C"确保C函数正确链接
extern "C" {
#include "rt_nonfinite.h"
#include "controller.h"
}


// 必须包含所有Simulink生成的源文件



// WiFi配置
const char* ssid = "TP-LINK_2470";
const char* password = "chaizhouzi";


// UDP配置
WiFiUDP udp;
const int localPort = 50024;
const int remotePort = 50025;


// 内存检查函数
void checkMemory() {
  Serial.printf("Free Heap: %d\n", ESP.getFreeHeap());
  Serial.printf("Min Free Heap: %d\n", ESP.getMinFreeHeap());
}


void setup() {
  Serial.begin(115200);
  delay(1000);
  
  checkMemory();

  // 连接WiFi
  Serial.printf("正在连接WiFi: %s\n", ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  unsigned long startTime = millis();
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (millis() - startTime > 20000) {
      Serial.println("\nWiFi连接超时");
      Serial.printf("WiFi状态: %d\n", WiFi.status());
      return;
    }
  }
  Serial.println("\nWiFi连接成功");
  Serial.printf("IP地址: %s\n", WiFi.localIP().toString().c_str());

  // 初始化UDP
  if(!udp.begin(localPort)) {
    Serial.println("UDP初始化失败");
    return;
  }

  // 初始化控制器
  controller_initialize();
}


void loop() {
  static unsigned long lastCheck = 0;
  if(millis() - lastCheck > 5000) {
    checkMemory();
    lastCheck = millis();
  }

  int packetSize = udp.parsePacket();
  if (packetSize > 0) {
    // 检查是否接收到完整的数据 (yr_1[3] + fd[3] + D_x[6] + x[6] = 18个real_T)
    if (packetSize == sizeof(controller_U.yr_1) + sizeof(controller_U.fd) + sizeof(controller_U.D_x) + sizeof(controller_U.x)) {
      // 读取输入数据
      udp.read((byte*)controller_U.yr_1, sizeof(controller_U.yr_1));
      udp.read((byte*)controller_U.fd, sizeof(controller_U.fd));
      udp.read((byte*)controller_U.D_x, sizeof(controller_U.D_x));
      udp.read((byte*)controller_U.x, sizeof(controller_U.x));
      
      // 执行控制器计算
      controller_step();
      
      // 发送结果回Simulink
      if(udp.beginPacket(udp.remoteIP(), remotePort)) {
        // 发送所有5个输出: x_gongji_11, x_gongji_12, y_d_gongji_1, u, yd_zitai
        int bytesWritten = 0;
        bytesWritten += udp.write((byte*)controller_Y.x_gongji_11, sizeof(controller_Y.x_gongji_11));
        bytesWritten += udp.write((byte*)controller_Y.x_gongji_12, sizeof(controller_Y.x_gongji_12));
        bytesWritten += udp.write((byte*)controller_Y.y_d_gongji_1, sizeof(controller_Y.y_d_gongji_1));
        bytesWritten += udp.write((byte*)controller_Y.u, sizeof(controller_Y.u));
        bytesWritten += udp.write((byte*)controller_Y.yd_zitai, sizeof(controller_Y.yd_zitai));
        
        // 计算预期的总字节数
        int expectedBytes = sizeof(controller_Y.x_gongji_11) + sizeof(controller_Y.x_gongji_12) + 
                           sizeof(controller_Y.y_d_gongji_1) + sizeof(controller_Y.u) + 
                           sizeof(controller_Y.yd_zitai);
        
        if(bytesWritten == expectedBytes) {
          udp.endPacket();
        } else {
          // 发送失败
        }
      }
    }
  }
  delay(10);
}
