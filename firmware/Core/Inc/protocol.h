#ifndef INC_PROTOCOL_H_
#define INC_PROTOCOL_H_

#include <stdint.h>




#define BOARD_DEVICE_ID  0b000110
#define JETSON_ID        0b000001

// Severity values
#define MEI_id_type      0b00
#define AEI_id_type      0b01
#define status_id_type   0b10
#define ctrl_id_type     0b11

// Instruction values
#define force_stop_id_bit 0b01
#define resume_id_bit     0b10
#define error_id_bit      0b11
#define motor_1_id_bit    0b1001
#define motor_2_id_bit    0b1010
#define motor_3_id_bit    0b1011
#define motor_4_id_bit    0b1100
#define motor_5_id_bit    0b1101
#define led_id_bit        0b1110

// Max angular velocity for duty cycle scaling
#define MAX_RADS 1024.0f

// ID composition

#define JETSON_MAKE_ID(severity, instruction) \
    ( ((uint32_t)(severity)     << 15) \
    | ((uint32_t)(instruction)  <<  7) \
    | ((uint32_t)JETSON_ID << 1) )

#define MAKE_ID(severity, instruction) \
    ( ((uint32_t)(severity)     << 15) \
    | ((uint32_t)(instruction)  <<  7) \
    | ((uint32_t)BOARD_DEVICE_ID << 1) )

// Pre-baked IDs (handy for TX-side use)
#define FORCE_STOP_ID MAKE_ID(ctrl_id_type,   force_stop_id_bit)
#define RESUME_ID     MAKE_ID(ctrl_id_type,   resume_id_bit)
#define ERROR_ID      MAKE_ID(status_id_type, error_id_bit)
#define MOTOR_1_ID    MAKE_ID(ctrl_id_type,   motor_1_id_bit)
#define MOTOR_2_ID    MAKE_ID(ctrl_id_type,   motor_2_id_bit)
#define MOTOR_3_ID    MAKE_ID(ctrl_id_type,   motor_3_id_bit)
#define MOTOR_4_ID    MAKE_ID(ctrl_id_type,   motor_4_id_bit)
#define MOTOR_5_ID    MAKE_ID(ctrl_id_type,   motor_5_id_bit)
#define LED_ID        MAKE_ID(ctrl_id_type,   led_id_bit)

void start_motors(void);
void stop_motors(void);

#endif





