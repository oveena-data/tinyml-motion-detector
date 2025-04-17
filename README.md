# TinyML Motion Detector

--

A basic TinyML project that detects motion patterns using an accelerometer (like the ADXL345) connected to an Arduino. Data is collected and used to train a simple machine learning model that can be deployed on a microcontroller.

-- 

## Tools needed:

- Arduino board (e.g. Arduino Nano 33 BLE Sense, UNO + external sensor)
- ADXL345 Accelerometer (or similar)
- Arduino IDE
- Python 3.7+
- Libraries: `pandas`, `numpy`, `scikit-learn`, `matplotlib`

--

## Project Flow:

1. **Data Collection:** Collect raw X, Y, Z accelerometer data from the Arduino and save as CSV.
2. **Model Training:** Use Python to train a basic classifier to detect a motion pattern.
3. **Deployment (Optional):** Convert the model to TensorFlow Lite (TFLite) for microcontroller deployment.

--

## 🚀 Run the Project:

1. Upload `motion_capture.ino` to Arduino.
2. Open Serial Monitor and save output to `data.csv`.
3. Run `train_model.py` to preprocess and train the model.
4. (Optional) Use Edge Impulse or TensorFlow Lite Micro to deploy to microcontroller.

--

## 🤖 Author

Built as a starter project to explore TinyML and edge ML applications.

--