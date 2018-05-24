/*
 * File:   nco_melody.c
 * Author: kane4d
 *
 * Created on 2018/01/16, 11:24
 */


#include "nco_melody.h"


void wait_note(notes_t len) {
    do {
        __delay_us(NOTE_TEMPO);
    } while (--len);

}

void toneOn(scales_t t, notes_t len) {
    /**
     * @brief 1オクターブ(C4-B4)分のNCO設定データ
     * @details 
     * FSC 1MHz以外では要再計算
     * この配列を元に倍音を計算して利用する
     */
    static const uint16_t scale_param16[] = {549/*C4*/, 581, 616, 652, 691, 732, 776, 822, 871, 923, 978, 1036/*B4*/};
    toneOff();
    CLRWDT();
    wait_note(NOTE_128TH);
    if (t < SCALE_MUTE) {
        if (t >= SCALE_C6) {
            setScale(scale_param16[ t - SCALE_C6 ] << 2);
        } else if (t >= SCALE_C5) {
            setScale(scale_param16[ t - SCALE_C5 ] << 1);
        } else {
            setScale(scale_param16[ t ]);
        }
        DSM_ManualModulationSet();
    }
    wait_note(len);
}

void playMelody(const tones_t* melody, uint16_t len) {
    for (uint16_t i = 0; i < len; i++) {
        toneOn(melody[i].scale, melody[i].note);
    }
    toneOff();
}

void playMelody_fullScale(notes_t len) {
    for (uint16_t i = 0; i < SizeOf_scales - 1; i++) {
        toneOn(i, len);
    }
}

void playMelody_pc98_pipo() {
    toneOff();
    DSM_ManualModulationSet();
    setScale(SCALE_PC98_PI);
    wait_note(NOTE_16TH_);
    mute(NOTE_128TH);
    DSM_ManualModulationSet();
    setScale(SCALE_PC98_PO);
    wait_note(NOTE_8TH_);
    toneOff();
}
