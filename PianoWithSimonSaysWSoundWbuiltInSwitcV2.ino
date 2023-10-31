const int buttonRelayPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 12};
const int speakerPin = 11; // Connect a 5V speaker here
const int modeSwitchPin = 23; // Connect a switch here for mode selection
const int maxRounds = 100; // Maximum rounds supported

bool switchModeRequested = false;
unsigned long switchModeStartTime = 0;
const int switchModeHoldTime = 3000; // Hold time in milliseconds (3 seconds)


// make the buttons be both the green buttons, pins unknown
// staet in piano mode

int* sequence;
int* userSequence;
int currentRound = 0;
bool simonSaysMode = true; // Start in Simon Says mode

void setup() {
  for (int i = 0; i < 10; i++) {
    pinMode(buttonRelayPins[i], INPUT_PULLUP);
  }
  pinMode(speakerPin, OUTPUT);
  randomSeed(analogRead(0));
  Serial.begin(9600);
}

void loop() {
  // Detect if buttons 2 and 12 are held simultaneously
  if (digitalRead(buttonRelayPins[0]) == LOW && digitalRead(buttonRelayPins[9]) == LOW) {
    switchModeRequested = true;
    switchModeStartTime = millis();
  }

  if (switchModeRequested && millis() - switchModeStartTime >= switchModeHoldTime) {
    simonSaysMode = !simonSaysMode;
    // resetGame();
    // playModeSwitchAnimation();
    playCircleAnimation();
    switchModeRequested = false;
  }

  if (simonSaysMode) {
    if (currentRound == 0 && sequence == nullptr) {
      sequence = new int[currentRound + 1];
      userSequence = new int[currentRound + 1];
      generateSequence();
      displaySequence();
    }
    getUserInput();
  } else {
    pianoMode();
  }
}


void pianoMode() {
  int notes[] = {262, 294, 330, 349, 392, 440, 494, 523, 587, 659}; // Frequencies for notes C4 to E5
  int buttonPressed = waitForButtonPress();
  tone(speakerPin, notes[buttonPressed], 500); // Play the note for 500 ms
  delay(100); // Add a small delay for better playability
}

void generateSequence() {
  for (int i = 0; i <= currentRound; i++) {
    sequence[i] = random(0, 10);
  }
}

void displaySequence() {
  for (int i = 0; i <= currentRound; i++) {
    turnOnRelay(sequence[i]);
    delay(500);
    turnOffRelay(sequence[i]);
    delay(250);
  }
}

void getUserInput() {
  for (int i = 0; i <= currentRound; i++) {
    int buttonPressed = waitForButtonPress();
    userSequence[i] = buttonPressed;
    turnOnRelay(buttonPressed);
    delay(250);
    turnOffRelay(buttonPressed);
    delay(250);
  }
  checkUserInput();
}

void playSuccessSound() {
  tone(speakerPin, 250);
  delay(200);
  tone(speakerPin, 523);// Play note C5 for 250 ms (Success sound)
  delay(300); // Add a small delay for better playability
  noTone(speakerPin); // Stop the tone
}

void playFailSound() {
  tone(speakerPin, 500);
  delay(200);
  tone(speakerPin, 262); // Play note C4 for 500 ms (Fail sound)
  delay(600); // Add a small delay for better playability
  noTone(speakerPin); // Stop the tone
}

void playRoundStartSound() {
  tone(speakerPin, 440);
  delay(200);
  tone(speakerPin, 250); // Play note A4 for 250 ms (Round start sound)
  delay(300); // Add a small delay for better playability
  noTone(speakerPin); // Stop the tone
}

int waitForButtonPress() {
  int buttonPressed = -1;
  while (buttonPressed == -1) {
    for (int i = 0; i < 10; i++) {
      if (digitalRead(buttonRelayPins[i]) == LOW) {
        buttonPressed = i;
        break;
      }
    }
  }
  while (digitalRead(buttonRelayPins[buttonPressed]) == LOW) {}
  return buttonPressed;
}

void checkUserInput() {
  for (int i = 0; i <= currentRound; i++) {
    if (userSequence[i] != sequence[i]) {
      resetGame();
      playFailSound(); // Play fail sound on incorrect input
      return;
    }
  }
  currentRound++;
  if (currentRound == maxRounds) {
    gameWon();
  } else {
    playSuccessSound(); // Play success sound on correct input
    int* newSequence = new int[currentRound + 1];
    int* newUserSequence = new int[currentRound + 1];
    memcpy(newSequence, sequence, currentRound * sizeof(int));
    memcpy(newUserSequence, userSequence, currentRound * sizeof(int));
    delete[] sequence;
    delete[] userSequence;
    sequence = newSequence;
    userSequence = newUserSequence;
    generateSequence();
    displaySequence();
  }
}

void turnOnRelay(int relayPin) {
  pinMode(buttonRelayPins[relayPin], OUTPUT);
  digitalWrite(buttonRelayPins[relayPin], LOW);
}

void turnOffRelay(int relayPin) {
  pinMode(buttonRelayPins[relayPin], INPUT_PULLUP);
}

void resetGame() {
  delete[] sequence;
  delete[] userSequence;
  currentRound = 0;
  sequence = nullptr;
  userSequence = nullptr;
}

void playModeSwitchAnimation() {
  int animationDelay = 300;
  for (int i = 0; i < 5; i++) { // Flash 5 times
    turnOnRelay(0);
    turnOnRelay(9);
    delay(animationDelay);
    turnOffRelay(0);
    turnOffRelay(9);
    delay(animationDelay);
  }
  delay(500); // Add a short pause after the animation
}

void playCircleAnimation() {
  int circleDelay = 200;
  for (int i = 0; i < 10; i++) {
      turnOnRelay(buttonRelayPins[i]);
      delay(circleDelay);
  }
  for (int i = 0; i < 10; i++) {
      turnOffRelay(buttonRelayPins[i]);
  }
}


void gameWon() {
  Serial.println("You Win!");
  // Add any additional win actions here
}