# 🌊 Mathe Praktikum 4 – Fouriertransformation mit komplexen Zahlen (C++)

Implementierung der **Diskreten Fouriertransformation (DFT)** mit komplexen Zahlen in C++ im Rahmen des Moduls *Mathematik 2* an der FH Aachen.

## 📌 Thema

Die Fouriertransformation zerlegt ein Signal in seine Frequenzanteile — Grundlage von Audio-Kompression (MP3), Bildkompression (JPEG) und Signalverarbeitung. Dieses Praktikum implementiert die DFT mit einer eigenen Klasse für komplexe Zahlen.

## 🚀 Implementierte Funktionalitäten

- Klasse `CKomplex` für komplexe Zahlen mit Operatoren
- **Diskrete Fouriertransformation (DFT)**
- **Inverse Fouriertransformation (IDFT)**
- Analyse von Signaldaten aus `.txt`-Dateien
- Bildrekonstruktion mit variablen Frequenzanteilen
- Visuelle Ergebnisse als `.png`-Dateien

## 🛠️ Technologien & Konzepte

- C++17
- Komplexe Zahlen (Real- und Imaginärteil)
- Operator-Überladung (`+`, `-`, `*`, `/`)
- Diskrete Fouriertransformation (DFT / IDFT)
- Dateiverarbeitung (`.txt` Ein-/Ausgabe)
- Signalanalyse & Bildverarbeitung

## 📁 Projektstruktur

```
Mathe-P4-Fouriertransformation/
├── CKomplex.h                    → Klasse für komplexe Zahlen
├── CKomplex.cpp                  → Implementierung der DFT/IDFT
├── main.cpp                      → Hauptprogramm & Signalanalyse
├── Daten_original1.txt           → Eingangssignal 1
├── Daten_original2.txt           → Eingangssignal 2
├── Testbild_original_64.txt      → Originalbild als Matrix
├── Testbild_rueck_trans_64_*.png → Rekonstruierte Bilder (10/30/100 Frequenzen)
└── Testbild_trans_64_*.txt       → Transformierte Bilddaten
```

## 📊 Ergebnisse

Die `.png`-Dateien zeigen die Bildrekonstruktion mit unterschiedlich vielen Frequenzanteilen:
- `_10` → nur 10 Frequenzen → unscharfes Bild
- `_100` → 100 Frequenzen → deutlich besser
- `_1000` → 1000 Frequenzen → fast originalgetreu

## ▶️ Kompilieren & Ausführen

```bash
g++ -std=c++17 -o fourier main.cpp CKomplex.cpp
./fourier
```

## 🎓 Modul

**Mathematik 2 (Mathe 2)**  
Fachhochschule Aachen – Wirtschaftsinformatik

## 👨‍💻 Autor

**Landry Channel Kamgang Fogang**
