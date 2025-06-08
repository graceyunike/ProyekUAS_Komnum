import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# === BACA DATA ===
df = pd.read_csv("data_energi.csv")

# === KOEFISIEN REGRESI DARI PROGRAM C ===
b0 = 201.3330
b1 = 1.5055  # luas
b2 = 5.1000  # jumlah alat
b3 = 1.9754  # suhu

# === HITUNG PREDIKSI DAN RESIDUAL ===
df['prediksi'] = b0 + b1 * df['luas'] + b2 * df['jumlah_alat'] + b3 * df['suhu']
df['residual'] = df['energi'] - df['prediksi']

# === PLOT 1: ENERGI AKTUAL VS PREDIKSI ===
plt.figure(figsize=(10,6))
sns.scatterplot(x=df['energi'], y=df['prediksi'], s=70, color='blue')
plt.plot([df['energi'].min(), df['energi'].max()],
         [df['energi'].min(), df['energi'].max()],
         color='red', linestyle='--', label='Ideal (y = x)')
plt.title("Plot Energi Aktual vs Prediksi")
plt.xlabel("Energi Aktual (kWh)")
plt.ylabel("Energi Prediksi (kWh)")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("plot_aktual_vs_prediksi.png")
plt.close()

# === PLOT 2: RESIDUAL ===
plt.figure(figsize=(10,5))
plt.scatter(range(len(df)), df['residual'], color='darkorange')
plt.axhline(y=0, color='gray', linestyle='--')
plt.title("Plot Residual (Energi Aktual - Prediksi)")
plt.xlabel("Index Data")
plt.ylabel("Residual (kWh)")
plt.grid(True)
plt.tight_layout()
plt.savefig("plot_residual.png")
plt.close()

# === PLOT 3: SUHU VS PREDIKSI ===
plt.figure(figsize=(10,6))
plt.scatter(df['suhu'], df['prediksi'], color='green')
plt.title("Plot Suhu vs Prediksi Konsumsi Energi")
plt.xlabel("Suhu Rata-rata (°C)")
plt.ylabel("Prediksi Energi (kWh)")
plt.grid(True)
plt.tight_layout()
plt.savefig("plot_suhu_vs_prediksi.png")
plt.close()

print("✅ Semua grafik berhasil disimpan sebagai file PNG.")
