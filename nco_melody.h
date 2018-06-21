/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   nco_melody.h
 * Author: kane4d
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef NCO_MELODY_H
#define	NCO_MELODY_H

#include <xc.h> // include processor files - each processor file is guarded.  

// TODO Insert appropriate #include <>
#include "mcc_generated_files/mcc.h"
// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */



    
    /**
     * @brief 配列の要素数     
     */
#define sizeOfArray(x) ( sizeof(x) / sizeof(x[0]) )
    
    /**
     * @brief 消音
     */
#define toneOff() DSM_ManualModulationClear();
    
    /**
     * @brief 音程をNCOに設定する
     * @param[in] x 音程
     */
#define setScale(x) {NCO1INC = x;}
    /**
     * @brief 指定時間消音する
     * @param[in] x 長さ mSec
     */
#define mute(x) {toneOff();wait_note(x);}

    /**
     * @brief 音の長さ mSec
     * @details
     *  テンポは倍速気味 130位？？
     *  whole   全音符
     *  half    2分音符
     *  quoter  4分音符
     *  quoter_ 付点4分音符
     */
    typedef enum {
        NOTE_WHOLE = 2400u,
        NOTE_HALF = 1200u,
        NOTE_QUOTER = 600u,
        NOTE_HALF_ = NOTE_HALF + NOTE_QUOTER,
        NOTE_8TH = 300u,
        NOTE_QUOTER_ = NOTE_QUOTER + NOTE_8TH,
        NOTE_16TH = 150u,
        NOTE_8TH_ = NOTE_8TH + NOTE_16TH,
        NOTE_32TH = 75u,
        NOTE_16TH_ = NOTE_16TH + NOTE_32TH,
        NOTE_64TH = 38u,
        NOTE_32TH_ = NOTE_32TH + NOTE_64TH,
        NOTE_128TH = 19u,
        NOTE_64TH_ = NOTE_64TH + NOTE_128TH,
        NOTE_MUTE = 10u,
        NOTE_2ms = 2u
    } notes_t;

#define NOTE_SHORT  (NOTE_8TH)
#define NOTE_LONG   (NOTE_QUOTER)


    /**
     * @brief 音階
     * @details
     * 音階データはtoneOn内のscale_param16を参照
     * scale_param16には1オクターブ(C4-B4)だけ定義されてる
     * SCALE_C4はド
     * SCALE_C4sはド#
     */
    typedef enum {
        SCALE_C4 = 0, /* C4 261.626Hz */
        SCALE_C4s,
        SCALE_D4,
        SCALE_D4s,
        SCALE_E4, /* E4 329.628 */
        SCALE_F4,
        SCALE_F4s,
        SCALE_G4, /* G4 391.995 */
        SCALE_G4s,
        SCALE_A4, /* A4 440.000 */
        SCALE_A4s,
        SCALE_B4,
        SCALE_C5, /* C5 523.251 */
        SCALE_C5s,
        SCALE_D5,
        SCALE_D5s,
        SCALE_E5, /* E5 659.255 */
        SCALE_F5,
        SCALE_F5s,
        SCALE_G5, /* G5 783.991 */
        SCALE_G5s,
        SCALE_A5, /* A5 880.000Hz */
        SCALE_A5s,
        SCALE_B5,
        SCALE_C6,
        SCALE_D6,
        SCALE_D6s,
        SCALE_E6,
        SCALE_F6,
        SCALE_F6s,
        SCALE_G6,
        SCALE_G6s,
        SCALE_A6,
        SCALE_A6s,
        SCALE_B6,
        SCALE_MUTE,
        SizeOf_scales
    } scales_t;

    void wait_note(notes_t len);

#define SCALE_PC98_PI    ( 4194u ) /* 2kHz 4194u */
#define SCALE_PC98_PO    ( 2097u ) /* 1kHz 2097u */
#define NOTE_PC98_PIPO   ( NOTE_8TH )


    /**
     * @brief テンポを微調整する定数
     */
#ifndef NOTE_TEMPO
#define NOTE_TEMPO (500u)
#endif
    /**
     * @brief テンポ
     */
    void wait_note(notes_t len);

    typedef struct {
        scales_t scale;
        notes_t note;
    } tones_t;

    /**
     * @brief 音程を指定時間 発声
     * @param[in] t 音程
     * @param[in] len 1音の長さ mSec
     * @details 
     */
    void toneOn(scales_t t, notes_t len);

    /**
     * @brief メロディーを演奏
     * @param[in] melody 演奏データ配列
     * @param[in] len 配列melodyのサイズ 
     * @details 
     */
    void playMelody(const tones_t* melody, uint16_t len);

    /**
     * @brief 全音階を演奏
     * @param[in] len 1音の長さ 
     * @details 
     */
    void playMelody_fullScale(notes_t len);

    /**
     * @brief Lowバッテリー時の演奏データ
     * @details 警告音
     */
    const tones_t melodyData_lowBatt[] = {
        {SCALE_E4, NOTE_SHORT},
        {SCALE_C4, NOTE_LONG},
        {SCALE_MUTE, NOTE_SHORT},
        {SCALE_E4, NOTE_SHORT},
        {SCALE_C4, NOTE_LONG},
        {SCALE_MUTE, NOTE_SHORT},
        {SCALE_E4, NOTE_SHORT},
        {SCALE_C4, NOTE_LONG},
        {SCALE_MUTE, NOTE_SHORT},
    };
    /**
     * @brief Lowバッテリー時を演奏
     * @details 警告音
     */
#define playMelody_lowBatt()   playMelody(melodyData_lowBatt, sizeOfArray(melodyData_lowBatt));

    /**
     * @brief ドミソドミソー
     * @details 
     */
    const tones_t melodyData_test[] = {
        {SCALE_C4, NOTE_SHORT},
        {SCALE_E4, NOTE_SHORT},
        {SCALE_G4, NOTE_LONG},
        {SCALE_MUTE, NOTE_SHORT},
        {SCALE_C5, NOTE_SHORT},
        {SCALE_E5, NOTE_SHORT},
        {SCALE_G5, NOTE_SHORT},
        {SCALE_C6, NOTE_LONG},
    };
    /**
     * @brief ドミソドミソー
     * @details 
     */
#define playMelody_test()   playMelody(melodyData_test, sizeOfArray(melodyData_test));

    const tones_t melodyData_halt[] = {
        {SCALE_C4, NOTE_LONG},
        {SCALE_MUTE, NOTE_SHORT},
        {SCALE_C4, NOTE_LONG},
        {SCALE_MUTE, NOTE_SHORT},
        {SCALE_C4, NOTE_LONG},
    };
#define playMelody_halt()   playMelody(melodyData_halt, sizeOfArray(melodyData_halt));

    /**
     * @brief シューベルトの子守歌の演奏データ
     * @details スリープ前に演奏する
     */
    const tones_t melodyData_sleep[] = {
        {SCALE_E4, NOTE_QUOTER_},
        {SCALE_E4, NOTE_8TH},
        {SCALE_G4, NOTE_HALF},
        {SCALE_D4, NOTE_QUOTER_},
        {SCALE_E4, NOTE_8TH},
        {SCALE_F4, NOTE_HALF},
    };
    /**
     * @brief シューベルトの子守歌を演奏 2小節だけ
     * @details スリープ前に演奏する
     */
#define playMelody_sleep()   playMelody(melodyData_sleep, sizeOfArray(melodyData_sleep) );

    /**
     * @brief チャルメラの演奏データ
     * @details 
     */
    const tones_t melodyData_charumera[] = {
        {SCALE_A4, NOTE_QUOTER},
        {SCALE_B4, NOTE_QUOTER},
        {SCALE_C5s, NOTE_HALF},
        {SCALE_B4, NOTE_QUOTER},
        {SCALE_A4, NOTE_QUOTER},

        {SCALE_MUTE, NOTE_WHOLE},

        {SCALE_A4, NOTE_QUOTER},
        {SCALE_B4, NOTE_QUOTER},
        {SCALE_C5s, NOTE_QUOTER},
        {SCALE_B4, NOTE_QUOTER},
        {SCALE_A4, NOTE_QUOTER},
        {SCALE_B4, NOTE_HALF},
        {SCALE_MUTE, NOTE_WHOLE},
    };
    /**
     * @brief チャルメラ
     * @details 
     */
#define playMelody_charumera()   playMelody(melodyData_charumera, sizeOfArray(melodyData_charumera) );

    /**
     * @brief 国民機PC-9801の起動音
     * @details 2kHzと1kHz
     * 生音 https://www.okqubit.net/98tunes/
     */
    void playMelody_pc98_pipo(void);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* NCO_MELODY_H */

