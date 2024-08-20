#include <WiFi.h>
#include <HTTPClient.h>

void enviarDatosPOST(String url, String postData) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(url);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    int httpResponseCode = http.POST(postData);
    
    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println(httpResponseCode);
      Serial.println(response);
    } else {
      Serial.println("Error en la solicitud POST");
    }

    http.end();
  } else {
    Serial.println("WiFi no está conectado");
  }
}


void setup() {
  Serial.begin(9600);
  WiFi.begin("Megacable_2.4G_6570", "4tCa7pFf"); //red
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a WiFi...");
  }

  Serial.println("Conectado a la red WiFi");

  // uso de la función para enviar datos
  String url = "http://192.168.1.8/recibir_datos.php"; // Cambiar esta IP a la del servidor
  String postData = "dato=Hola desde ESP32";
  enviarDatosPOST(url, postData);
}

void loop() {
  
}
