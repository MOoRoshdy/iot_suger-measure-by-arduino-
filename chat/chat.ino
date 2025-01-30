#include <SD.h>           // Include SD module library
#include <TMRpcm.h>       // Include TMRpcm library for audio playback

#define SD_ChipSelectPin 4  // Define chip select pin for SD card

TMRpcm sound;                 // Create an object for the TMRpcm library

void setup() {
  // Serial communication setup
  Serial.begin(9600);
  Serial.println("Initializing SD card...");

  if (!SD.begin(SD_ChipSelectPin)) {           // Initialize SD card
    Serial.println("SD card initialization failed.");
    while (true);                              // Halt execution if SD initialization fails
  }
  Serial.println("SD card initialization successful.");

  // TMRpcm setup
  sound.speakerPin = 9;                        // Set speaker pin (must be 9 for TMRpcm)
  sound.quality(1);                            // Set audio quality: 0 = default, 1 = oversampling
  sound.setVolume(5);                          // Set volume (0 to 7)

  // Check if the file exists and play it
  if (SD.exists("normal.wav")) {
    Serial.println("Playing like.wav...");
    sound.play("normal.wav");                    // Play the audio file
  } else {
    Serial.println("Error: like.wav file not found!");
  }
}

void loop() {
  // Continuously check if playback has stopped and restart the file
  if (!sound.isPlaying()) {
    sound.play("normal.wav");
  }
}
