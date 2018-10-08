#include"jugador.h"

#include "Pantallas/pantallaJuego.h"

namespace Juego {
	namespace Jugador {
		Jug jugador[cantJug];
		float tamanioXJug = 0;
			float tamanioYJug = 0;
			float velocidadJug = 0;

		Jug crearJugador(int numJug) {
			if (numJug != 1) {
				jugador[numJug].pos = { 0 + tamanioXJug, ((float)GetScreenHeight() - tamanioYJug) / 2 };
			}
			else {
				jugador[numJug].pos = { (float)GetScreenWidth() - 2 * tamanioXJug, ((float)GetScreenHeight() - tamanioYJug) / 2 };
			}

			jugador[numJug].tamanio = { tamanioXJug, tamanioYJug };

			jugador[numJug].goles = 0;
			return jugador[numJug];
		}

		void moverJug() {
			if (IsKeyDown(KEY_UP)) jugador[1].pos.y -= velocidadJug * GetFrameTime();
			if ((jugador[1].pos.y) <= 0) jugador[1].pos.y = 0;
			if (IsKeyDown(KEY_DOWN)) jugador[1].pos.y += velocidadJug * GetFrameTime();
			if ((jugador[1].pos.y + jugador[1].tamanio.y) >= GetScreenHeight()) jugador[1].pos.y = GetScreenHeight() - jugador[1].tamanio.y;

			if (IsKeyDown(KEY_W)) jugador[0].pos.y -= velocidadJug * GetFrameTime();
			if ((jugador[0].pos.y) <= 0) jugador[0].pos.y = 0;
			if (IsKeyDown(KEY_S)) jugador[0].pos.y += velocidadJug * GetFrameTime();
			if ((jugador[0].pos.y + jugador[0].tamanio.y) >= GetScreenHeight()) jugador[0].pos.y = GetScreenHeight() - jugador[0].tamanio.y;
		}

		void dibujarJug() {
			for (int i = 0; i < cantJug; i++) {
				DrawRectangleV(jugador[i].pos, jugador[i].tamanio, BLACK);
			}
		}

		void inicializarJug() {
			tamanioXJug = (float)(GetScreenWidth()*2.0 / 100.0);
			tamanioYJug = (float)(GetScreenHeight()*15.0 / 100.0);
			velocidadJug = (float)(GetScreenHeight() * 80.0 / 100.0);
			
			for (int i = 0; i < cantJug; i++) {
				crearJugador(i);
			}
			PantallaJuego::fase = PantallaJuego::inicio;
			jugador[0].goles = 0;
			jugador[1].goles = 0;
		}
	}
}