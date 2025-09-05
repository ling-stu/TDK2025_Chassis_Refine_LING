#ifndef INC_CONTROL_LIB_PINPOINT_INC_PINPOINT_HPP_
#define INC_CONTROL_LIB_PINPOINT_INC_PINPOINT_HPP_

#ifdef __cplusplus

#include <cstdint>
#include <cstring>
#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "stm32f4xx_it.h"
#include "stm32f446xx.h"

class PinpointI2C {
public:
    // ---- 公用型別 ----
    enum class DeviceStatusBits : uint32_t {
        NOT_READY           = 0,
        READY               = (1u << 0),
        CALIBRATING         = (1u << 1),
        X_POD_NOT_DETECTED  = (1u << 2),
        Y_POD_NOT_DETECTED  = (1u << 3),
    };

    struct Pose {
        float x_mm;
        float y_mm;
        float heading;
    };

    struct Velocity {
        float vx_mm_s;
        float vy_mm_s;
        float w_rad_s;
    };

    struct BulkData {
        uint32_t device_status;
        uint32_t loop_time_us;
        uint32_t enc_x_raw;
        uint32_t enc_y_raw;
        float    pos_x_mm;
        float    pos_y_mm;
        float    heading_rad;
        float    vel_x_mm_s;
        float    vel_y_mm_s;
        float    vel_h_rad_s;
    };

    struct Config {
        float ticks_per_mm = 19.894f;
        float x_offset_mm  = 0.0f;
        float y_offset_mm  = 0.0f;
        float yaw_scalar   = 1.0f;
    };

    enum class EncDir : uint8_t { Forward, Reversed };

    // ---- 生命週期 ----
    PinpointI2C(I2C_HandleTypeDef* hi2c, uint8_t addr7bit = 0x31, uint32_t timeoutMs = 10);

    // ---- 連線/健康檢測 ----
    bool ping();
    void setMaxConsecutiveErrors(uint8_t n);
    bool isConnected() const;
    uint8_t consecutiveErrors() const;

    // ---- 基本動作 ----
    bool readDeviceID(uint32_t& id);
    bool readDeviceVersion(uint32_t& ver);
    bool readDeviceStatus(uint32_t& status);
    bool readLoopTime(uint32_t& us);
    bool readRawEncoders(uint32_t& encX, uint32_t& encY);

    bool readBulk(BulkData& out);

    // ---- 位置/速度 ----
    bool readPosition(Pose& p);
    bool readVelocity(Velocity& v);

    // ---- 設定參數 ----
    bool setTicksPerMM(float tpm);
    bool setOffsets(float x_offset_mm, float y_offset_mm);
    bool setYawScalar(float yaw_scalar);

    // ---- 控制 ----
    bool resetIMU();
    bool resetPosAndIMU();
    bool setEncoderDirections(EncDir x, EncDir y);

    // ---- 直接覆寫位置 ----
    bool writePosition(const Pose& p);

    void Pinpoint_Init();
    void Pinpoint_TaskLoop();

private:
    I2C_HandleTypeDef* hi2c_;
    uint16_t devAddr_;
    uint32_t timeoutMs_;
    uint8_t  maxConsecutiveErrors_ = 5;
    uint8_t  consecutiveErrors_ = 0;

    // 寄存器定義
    static constexpr uint8_t REG_DEVICE_ID      = 1;
    static constexpr uint8_t REG_DEVICE_VER     = 2;
    static constexpr uint8_t REG_DEVICE_STATUS  = 3;
    static constexpr uint8_t REG_DEVICE_CTRL    = 4;
    static constexpr uint8_t REG_LOOP_TIME      = 5;
    static constexpr uint8_t REG_ENC_X          = 6;
    static constexpr uint8_t REG_ENC_Y          = 7;
    static constexpr uint8_t REG_POS_X          = 8;
    static constexpr uint8_t REG_POS_Y          = 9;
    static constexpr uint8_t REG_POS_H          = 10;
    static constexpr uint8_t REG_VEL_X          = 11;
    static constexpr uint8_t REG_VEL_Y          = 12;
    static constexpr uint8_t REG_VEL_H          = 13;
    static constexpr uint8_t REG_TICKS_PER_MM   = 14;
    static constexpr uint8_t REG_X_OFFSET       = 15;
    static constexpr uint8_t REG_Y_OFFSET       = 16;
    static constexpr uint8_t REG_YAW_SCALAR     = 17;
    static constexpr uint8_t REG_BULK           = 18;

    // 控制暫存器 bit
    static constexpr uint32_t CTRL_RESET_IMU            = (1u << 0);
    static constexpr uint32_t CTRL_RESET_POS_AND_IMU    = (1u << 1);
    static constexpr uint32_t CTRL_SET_Y_REV            = (1u << 2);
    static constexpr uint32_t CTRL_SET_Y_FWD            = (1u << 3);
    static constexpr uint32_t CTRL_SET_X_REV            = (1u << 4);
    static constexpr uint32_t CTRL_SET_X_FWD            = (1u << 5);

    // 低階 I2C 讀寫
    bool regRead(uint8_t reg, void* buf, uint16_t len);
    bool regWrite(uint8_t reg, const void* buf, uint16_t len);
    bool writeU32(uint8_t reg, uint32_t v);
    bool readU32(uint8_t reg, uint32_t& v);
    bool writeF32(uint8_t reg, float v);
    bool readF32(uint8_t reg, float& v);

    void onOk();
    void onErr();
};

#endif /* __cplusplus */

#endif /* INC_CONTROL_LIB_PINPOINT_INC_PINPOINT_HPP_ */