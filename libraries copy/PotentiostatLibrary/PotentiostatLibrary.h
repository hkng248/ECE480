#ifndef PotentiostatLibrary_h // TL
#define PotentiostatLibrary_h // TL

#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include "pins_arduino.h"
  #include "WConstants.h"
#endif

class PotentiostatLibrary
{
  public:

    PotentiostatLibrary(); // Constructor
    void init( double delayTimeHigh, double delayTimeLow,
      double quietTime, double squareWaveAmpltudeVoltage,
      double squareWaveStepVoltage, double startVoltage, double stopVoltage);

    void setPinsToOutput();
    void setPinsToInput();
    void setWritePinToOutput();
    double determineDigitalPinToSet(double currentStep);
    void writeToDigitalPin( int digitalPin, int value);
    void outputDigitalValues( int digitalEquivalentValue);
    double convertValueToVoltage(double value);
    int convertVoltageForDAC(int desiredVoltage);
    double readCurrent();
    void printCurrent(double current);

    // Linear sweep functions
    void linearSweepAlgorithm(double startVoltage, double stopVoltage);
    void setLinearSweepRepititions(double repititions) {mLinearSweepRepititions = repititions;}
    void setLinearSweepParameters(double startVoltage, double stopVoltage);
    int executeLinearSweep();

    // Square wave functions
    void squareWaveAlgorithm( double delayTimeHigh, double delayTimeLow,
      double startValue, double stopValue, double squareWaveAmplitude,
      double squareWaveStep);
    void executePulse();

    // Pin declarations
    int mDigitalPinZero = 24;
    int mDigitalPinOne = 26;
    int mDigitalPinTwo = 28;
    int mDigitalPinThree = 30;
    int mDigitalPinFour = 32;
    int mDigitalPinFive = 46;
    int mDigitalPinSix = 44;
    int mDigitalPinSeven = 42;
    int mDigitalPinEight = 40;
    int mDigitalPinNine = 38;
    int mDigitalPinTen = 36;
    int mDigitalPinEleven = 34;

    // Output pin to control writing to the DAC
    int mDigitalPinWR = 23;

    // Square wave parameters
    int mQuietTime = 0;
    int mDelayTimeHigh = 0;
    int mDelayTimeLow = 0;
    double mSquareWaveAmplitudeVoltage = 0;
    double mSquareWaveStepVoltage = 0;
    double mStartVoltage = 0;
    double mStopVoltage = 0;

    // Linear Sweep
    double mLinearSweepRepititions = 0;
    double mLinearSweepMinVoltage = -2.0;
    double mLinearSweepMaxVoltage = 2.0;
    double mLinearSweepStep = 0.001;

    // Uno
    //int mAnalogPinOne = A5;
    //int mAnalogPinTwo = A4;

    // Mega
    int mAnalogPinOne = A15;
    int mAnalogPinTwo = A14;
    double mADCValueToVoltageRatio = 4878.0 / 1024.0;
    double mADCValue = 0;
    double mCurrent = 0;
};
#endif
