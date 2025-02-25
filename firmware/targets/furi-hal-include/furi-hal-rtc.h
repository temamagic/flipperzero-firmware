/**
 * @file furi-hal-rtc.h
 * Furi Hal RTC API
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <main.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    // Time
    uint8_t hour;   /**< Hour in 24H format: 0-23 */
    uint8_t minute; /**< Minute: 0-59 */
    uint8_t second; /**< Second: 0-59 */
    // Date
    uint8_t day;    /**< Current day: 1-31 */
    uint8_t month;  /**< Current month: 1-12 */
    uint16_t year;  /**< Current year: 2000-2099 */
    uint8_t weekday;/**< Current weekday: 1-7 */
} FuriHalRtcDateTime;

typedef enum {
    FuriHalRtcFlagDebug = (1<<0),
    FuriHalRtcFlagFactoryReset = (1<<1),
    FuriHalRtcFlagLock = (1<<2),
} FuriHalRtcFlag;

typedef enum {
    FuriHalRtcRegisterBoot,
    FuriHalRtcRegisterBootVersion,
    FuriHalRtcRegisterSystem,
    FuriHalRtcRegisterSystemVersion,
    FuriHalRtcRegisterLfsFingerprint,
} FuriHalRtcRegister;

/** Initialize RTC subsystem */
void furi_hal_rtc_init();

uint32_t furi_hal_rtc_get_register(FuriHalRtcRegister reg);

void furi_hal_rtc_set_register(FuriHalRtcRegister reg, uint32_t value);

void furi_hal_rtc_set_log_level(uint8_t level);

uint8_t furi_hal_rtc_get_log_level();

void furi_hal_rtc_set_flag(FuriHalRtcFlag flag);

void furi_hal_rtc_reset_flag(FuriHalRtcFlag flag);

bool furi_hal_rtc_is_flag_set(FuriHalRtcFlag flag);

void furi_hal_rtc_set_datetime(FuriHalRtcDateTime* datetime);

void furi_hal_rtc_get_datetime(FuriHalRtcDateTime* datetime);

bool furi_hal_rtc_validate_datetime(FuriHalRtcDateTime* datetime);

#ifdef __cplusplus
}
#endif
