#include <WiFi.h>
#include <WiFiUdp.h>
#include "controller1.h"
#include "controller1_include.h"

// 必须包含所有Simulink生成的源文件


// WiFi配置
const char* ssid = "TP-LINK_2470";
const char* password = "chaizhouzi";

// UDP配置
WiFiUDP udp;
const int localPort = 50022;
const int remotePort = 50023;

// 控制器变量
RT_MODEL_controller1_T controller1_M;
B_controller1_T controller1_B;
DW_controller1_T controller1_DW;
real_T controller1_U_In1[6] = {0};
real_T controller1_U_x[6] = {0};
real_T controller1_Y_u[6] = {0};

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

  // 初始化控制器模型的blockIO和dwork指针
  controller1_M.blockIO = &controller1_B;
  controller1_M.dwork = &controller1_DW;
  
  // 初始化控制器
  controller1_initialize(&controller1_M, controller1_U_In1, controller1_U_x, controller1_Y_u);
}

void loop() {
  static unsigned long lastCheck = 0;
  if(millis() - lastCheck > 5000) {
    checkMemory();
    lastCheck = millis();
  }

  int packetSize = udp.parsePacket();
  if (packetSize > 0) {
    // 检查是否接收到完整的数据 (In1[6] + x[6] = 12个real_T)
    if (packetSize == sizeof(controller1_U_In1) + sizeof(controller1_U_x)) {
      // 读取输入数据
      udp.read((byte*)controller1_U_In1, sizeof(controller1_U_In1));
      udp.read((byte*)controller1_U_x, sizeof(controller1_U_x));
      
      // 执行控制器计算
      controller1_step(&controller1_M, controller1_U_In1, controller1_U_x, controller1_Y_u);
      
      // 发送结果回Simulink
      if(udp.beginPacket(udp.remoteIP(), remotePort)) {
        int bytesWritten = udp.write((byte*)controller1_Y_u, sizeof(controller1_Y_u));
        if(bytesWritten == sizeof(controller1_Y_u)) {
          udp.endPacket();
        } else {
          // 发送失败
        }
      }
    }
  }
  delay(10);
}
