#include "bola.h"

#include<cmath>

#include"Pantallas/pantallaJuego.h"

namespace Juego {
	namespace Bola {
		using namespace PantallaJuego;
		Pelota bola;
		Pelota crearBola() {
			bola.pos = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };
			bola.radio = GetScreenHeight() * 2 / 100;
			bola.velocidad = { (float)(GetScreenWidth()*50.0 / 100.0),(float)(GetScreenHeight()*50.0 / 100.0) };
			bola.aceleracion = { 0.0,0.0 };
			return bola;
		}

		void moverBola() {
			if (fase == inicio) {
				fase = juego;
				crearBola();
				int angMaximoInicial = 100;
				float anguloInicial = (float)GetRandomValue(-angMaximoInicial, angMaximoInicial) / 100;
				int multiplicador = 1;
				do {
					multiplicador = GetRandomValue(-1, 1);
					bola.aceleracion.x = multiplicador * cos(anguloInicial);
				} while (multiplicador == 0);

				bola.aceleracion.y = sin(anguloInicial);
			}
			if (fase == juego) {
				bola.pos.x += (bola.velocidad.x*bola.aceleracion.x)*GetFrameTime();
				bola.pos.y += (bola.velocidad.y*bola.aceleracion.y)*GetFrameTime();
			}
		}

		void dibujarBola() {
			DrawCircleV(bola.pos, bola.radio, RED);
		}
	}
}