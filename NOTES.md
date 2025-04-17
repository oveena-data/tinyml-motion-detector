# 📓 NOTES.md - TinyML Motion Detection Project

## Hardware Components

- **Microcontroller**: Arduino Nano 33 BLE Sense (or similar)
- **Sensor**: Adafruit ADXL345 (Triple-axis accelerometer)
- **Connection**: I2C interface (SDA/SCL)

---

## Libraries Used

These are essential to run the sketch successfully:

- `Wire.h` – for I2C communication
- `Adafruit_Sensor.h` – generic sensor abstraction
- `Adafruit_ADXL345_U.h` – ADXL345 accelerometer support

Install them from:
**Arduino IDE → Tools → Manage Libraries**

Search and install:
- `Adafruit Unified Sensor`
- `Adafruit ADXL345`

---

## Code Logic Overview

The Arduino sketch does the following:

1. **Initializes I2C and ADXL345**
2. **Reads acceleration data (x, y, z)**
3. **Calculates basic motion logic** (absolute threshold difference)
4. **Classifies motion as "Stationary" or "Moving"**
5. **Outputs results over serial**

---

## TinyML Concepts

- **TinyML**: Deploying machine learning models on edge devices with limited resources (memory, power, compute).
- **Model Type**: You can train a classification model (e.g., decision tree, neural net) to distinguish between stationary and motion sequences.
- **Inference on Microcontroller**: Use TensorFlow Lite for Microcontrollers (TFLM) to run trained models on-device.

---

## Data Collection Strategy

1. Collect raw accelerometer data using Serial Monitor.
2. Label samples as "Moving" or "Stationary".
3. Save as CSV and preprocess (normalization, feature extraction).
4. Train a classifier in Python (e.g., Random Forest, SVM, or small neural net).
5. Convert model to `.tflite` and use [TensorFlow Lite for Microcontrollers](https://www.tensorflow.org/lite/microcontrollers).

---

## Example Output

```txt
X: -10.23 | Y: 0.92 | Z: 9.81 | Motion: Stationary
X: 1.01  | Y: 2.23 | Z: 8.22 | Motion: Moving
