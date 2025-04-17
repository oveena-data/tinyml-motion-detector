import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import classification_report
import matplotlib.pyplot as plt

# Load data
data = pd.read_csv("data.csv", names=["x", "y", "z"])
# Add dummy labels for now (e.g., 0: still, 1: shake)
data['label'] = [0 if abs(x)+abs(y)+abs(z) < 3 else 1 for x, y, z in zip(data.x, data.y, data.z)]

# Train/test split
X = data[['x', 'y', 'z']]
y = data['label']
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Train model
model = RandomForestClassifier(n_estimators=50)
model.fit(X_train, y_train)

# Evaluate
preds = model.predict(X_test)
print(classification_report(y_test, preds))

# Save model (optional)
import joblib
joblib.dump(model, "motion_model.pkl")

# Plotting
plt.scatter(data['x'], data['y'], c=data['label'], cmap='coolwarm', s=5)
plt.title("Motion Data Label Visualization")
plt.xlabel("X Acceleration")
plt.ylabel("Y Acceleration")
plt.show()
