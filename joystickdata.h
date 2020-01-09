#ifndef JOYSTICKDATA_H
#define JOYSTICKDATA_H

typedef struct {
        int32_t xAxis;
        int32_t yAxis;
        int32_t zAxis;
        bool button0;
        bool button1;
        bool button2;
        bool button3;
        bool button4;
        bool button5;
        bool button6;
        bool button7;
        bool isNewEvent;
} JOYSTICK_DATA;

#endif // JOYSTICKDATA_H
