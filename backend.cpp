#include "backend.h"
#include <QDebug>

BackEnd::BackEnd(QObject *parent) : QObject(parent)
{
    // Initialize connection status
    checkConnection();
}

void BackEnd::change_temperature_sh(const quint16 &temperature_sh) {
    m_temperature_sh = temperature_sh;
    qDebug() << "Temperature set to: " << m_temperature_sh;
    emit temperature_sh_changed();
}

void BackEnd::envoyerTemperature(const quint16 &temperature_sh) {
    if (m_isConnected) {
        m_temperature_sh = temperature_sh;
        qDebug() << "Sending temperature: " << m_temperature_sh;
        emit temperature_sh_changed();
    } else {
        qDebug() << "Raspberry Pi not connected. Cannot send temperature.";
    }
}

void BackEnd::checkConnection() {
    // Simuler l'état de la connexion
    m_isConnected = false;  // Mettre à false pour simuler une absence de connexion
    emit connectionStatusChanged();
}
