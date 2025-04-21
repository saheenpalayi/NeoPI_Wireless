/*
    Spindle.cpp

    A Base class for spindles and spinsle like things such as lasers

    Part of Grbl_ESP32

    2020 -  Bart Dring
    2025 -  Saheen Palayi, Vishnu, This file modified for adding Second 
            serial port and send the spindle commands through the second serial for the Velichapad CNC machine. 

    Grbl is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    Grbl is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with Grbl.  If not, see <http://www.gnu.org/licenses/>.

    TODO
        Add Spindle spin up/down delays

    Get rid of dependance on machine definition #defines
        SPINDLE_OUTPUT_PIN
        SPINDLE_ENABLE_PIN
        SPINDLE_DIR_PIN

*/
#include "../Grbl_Esp32/src/Grbl.h"

#include "Spindle.h"
// #include <../Grbl_Esp32/src/EspNow.h>
// #include <EspNow.h>
#include "NullSpindle.h"
#include "PWMSpindle.h"
#include "RelaySpindle.h"
#include "Laser.h"
#include "DacSpindle.h"
#include "HuanyangSpindle.h"
#include "H2ASpindle.h"
#include "BESCSpindle.h"
#include "10vSpindle.h"
#include "YL620Spindle.h"
#include "TecoL510.h"


// uint8_t receiverMac[] = {0x8C, 0xBF, 0xEA, 0xCB, 0x7E, 0xC8};

// EspNow device(receiverMac);


namespace Spindles {
    // An instance of each type of spindle is created here.
    // This allows the spindle to be dynamicly switched

    Null     null;
    PWM      pwm;
    Relay    relay;
    Laser    laser;
    Dac      dac;
    Huanyang huanyang;
    H2A      h2a;
    BESC     besc;
    _10v     _10v;
    YL620    yl620;
    L510     l510;

    void Spindle::select() {
        switch (static_cast<SpindleType>(spindle_type->get())) {
            case SpindleType::PWM:
                spindle = &pwm;
                break;
            case SpindleType::RELAY:
                spindle = &relay;
                break;
            case SpindleType::LASER:
                spindle = &laser;
                break;
            case SpindleType::DAC:
                spindle = &dac;
                break;
            case SpindleType::HUANYANG:
                spindle = &huanyang;
                break;
            case SpindleType::BESC:
                spindle = &besc;
                break;
            case SpindleType::_10V:
                spindle = &_10v;
                break;
            case SpindleType::H2A:
                spindle = &h2a;
                break;
            case SpindleType::YL620:
                spindle = &yl620;
                break;
            case SpindleType::L510:
                spindle = &l510;
                break;
            case SpindleType::NONE:
            default:
                spindle = &null;
                break;
        }

        spindle->init();
    }

    // ========================= Spindle ==================================

    bool Spindle::inLaserMode() {
        return false;  // default for basic spindle is false
    }

    void Spindle::sync(SpindleState state, uint32_t rpm) {
        if (sys.state == State::CheckMode) {
            return;
        }
        char buffer[32];
        protocol_buffer_synchronize();  // Empty planner buffer to ensure spindle is set when programmed.
        set_state(state, rpm);
        // sendESPNOWData(1, state);
        sprintf(buffer, "M%d S%d \n", static_cast<int>(state), static_cast<int32_t>(rpm));
        #ifdef UART1_ENABLE
            Uart1.write(buffer);
        #endif

    }

    void Spindle::deinit() { stop(); }
}

Spindles::Spindle* spindle;
