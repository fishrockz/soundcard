#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s2;           //xy=139.4499969482422,386.4499969482422
AudioInputUSB            usb2;           //xy=140.4499969482422,491.4499969482422
AudioOutputUSB           usb1;           //xy=396.4499969482422,391.4499969482422
AudioOutputI2S           i2s1;           //xy=402.4499969482422,500.4499969482422
AudioConnection          patchCord1(i2s2, 0, usb1, 0);
AudioConnection          patchCord2(i2s2, 1, usb1, 1);
AudioConnection          patchCord3(usb2, 0, i2s1, 0);
AudioConnection          patchCord4(usb2, 1, i2s1, 1);
// GUItool: end automatically generated code

AudioControlSGTL5000     sgtl5000_1;     //xy=302,184


void setup() {                
  AudioMemory(12);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.6);
}

void loop() {
  // read the PC's volume setting
  float vol = usb2.volume();

  // scale to a nice range (not too loud)
  // and adjust the audio shield output volume
  if (vol > 0) {
    // scale 0 = 1.0 range to:
    //  0.3 = almost silent
    //  0.8 = really loud
    vol = 0.3 + vol * 0.5;
  }

  // use the scaled volume setting.  Delete this for fixed volume.
  sgtl5000_1.volume(vol);

  delay(100);
}

// Teensyduino 1.35 & earlier had a problem with USB audio on Macintosh
// computers.  For more info and a workaround:
// https://forum.pjrc.com/threads/34855-Distorted-audio-when-using-USB-input-on-Teensy-3-1?p=110392&viewfull=1#post110392

