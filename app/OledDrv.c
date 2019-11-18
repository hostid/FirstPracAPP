/*
 * @FileName: 
 * @Descripttion: 
 * @Author: jiangfeng.zhang(jiangfeng.zhang@aliyun.com)
 * @LastEditTime: 2019-11-18 17:57:31
 */
#include "u8g2.h"
#include "OledDrv.h"
u8g2_t g_oledFd; //define global u8g2  handle

static uint8_t HardwareSpiCallBack(u8x8_t *u8x8,
                                   uint8_t msg,
                                   uint8_t arg_int,
                                   void *arg_ptr);

static uint8_t SoftwareSpiCallBack(U8X8_UNUSED u8x8_t *u8x8,
                                   U8X8_UNUSED uint8_t msg,
                                   U8X8_UNUSED uint8_t arg_int,
                                   U8X8_UNUSED void *arg_ptr);

void OledSSD1309Init()
{
    u8g2_Setup_ssd1309_128x64_noname2_1(&g_oledFd, U8G2_R0, HardwareSpiCallBack, SoftwareSpiCallBack);
    u8g2_InitDisplay(&g_oledFd);
    u8g2_SetPowerSave(&g_oledFd, 0);
}

static uint8_t HardwareSpiCallBack(u8x8_t *u8x8,
                                   uint8_t msg,
                                   uint8_t arg_int,
                                   void *arg_ptr)
{
    uint8_t *data = NULL;
    switch (msg)
    {
    case U8X8_MSG_BYTE_SEND:
        data = (uint8_t *)arg_ptr;
        //send data
        break;
    case U8X8_MSG_BYTE_INIT:
        //oled init,if this master is ruing every once?
        break;
    case U8X8_MSG_BYTE_SET_DC:
        //set dc pin
        break;
    case U8X8_MSG_BYTE_START_TRANSFER:
        break;
    case U8X8_MSG_BYTE_END_TRANSFER:
        //stop
        break;
    default:
        return 0;
    }
    return 1;
}

static uint8_t SoftwareSpiCallBack(U8X8_UNUSED u8x8_t *u8x8,
                                   U8X8_UNUSED uint8_t msg,
                                   U8X8_UNUSED uint8_t arg_int,
                                   U8X8_UNUSED void *arg_ptr)
{
    //do nothing
    return 1;
}

void OledDrawTest()
{
    u8g2_ClearBuffer(&g_oledFd);
    u8g2_SetFontMode(&g_oledFd, 1);
    u8g2_SetFontDirection(&g_oledFd, 0);
    u8g2_SetFont(&g_oledFd, u8g2_font_helvB18_te);
    u8g2_DrawStr(&g_oledFd, 0, 24, "hello world");
    u8g2_DrawStr(&g_oledFd, 0, 50, "i am Re.");
    u8g2_SetFont(&g_oledFd, u8g2_font_u8glib_4_tf);
    u8g2_DrawStr(&g_oledFd, 0, 60, "2018-01-18");
    u8g2_SendBuffer(&g_oledFd);
}