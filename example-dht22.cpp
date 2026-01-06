#include "dht.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

void dht_22(void *arg)
{
    static const char *TAG = "DHT22";
    while (1)
    {
        if (!dht22::getData(GPIO_NUM_4))
        {
            ESP_LOGE(TAG, "Error");
        }

        ESP_LOGI(TAG, "Temp: %.2f", dht22::getTEMP());
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

extern "C" void app_main()
{
    dht22::init(GPIO_NUM_5);
    xTaskCreatePinnedToCore(dht_22, "get temp and hum", 2048, NULL, 4, NULL, 1);
}
