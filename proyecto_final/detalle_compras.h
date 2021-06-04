#pragma once
#include<mysql.h>
#include <iostream>
#include"ConexionBD.h"
#include "compras.h"
#include<string>

using namespace std;

class detalle_compras {
	// atributos

	   // metodo constructor
protected: string cantidad, precio_costo_u, id_Compras, id_Producto;
		 //int id_Producto = 0;
public:
	detalle_compras() {
	}

	detalle_compras(string cn, string idpro, string cantc, string pcu) {
		id_Compras = cn;
		id_Producto = idpro;
		cantidad = cantc;
		precio_costo_u = pcu;
		
	}
	// metodos de modificar datos
	// set ( modificar)
	void setcantidad(string cantc) { cantidad = cantc; }
	void setprecio_costo_u(string pcu) { precio_costo_u = pcu; }
	void setid_Producto(string idpro) { id_Producto = idpro; }
	void setid_Compras(string cn) { id_Compras = cn; }


	// get(mostrar)
	string getcantidad() { return cantidad; }
	string getprecio_costo_u() { return precio_costo_u; }
	string getid_Producto() { return id_Producto; }
	string getid_Compras() { return id_Compras; }



	void crearComprasDetalle() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		string produc = id_Producto;

		cn.abrir_conexion();
		if (cn.getConectar()) {

			string insert = " insert into compras_detalle (idcompra,idproducto, cantidad, precio_costo_unitario) VALUES (" + id_Compras + "," + id_Producto + ",  " + cantidad + "," + precio_costo_u + ");";
			// executar el query
			const char* h = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), h);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}

		cn.cerrar_conexion();
	}

	void leerComprasDetalle(string idcompra) {

		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			cout << "\n" << endl;
			cout << "----------------------------DETALLE COMPRAS------------------------" << endl;
			cout << "\n" << endl;
			string consulta = "select  cd.idcompras_detalle, cd.idcompra, cd.idproducto, p.producto, cd.cantidad, cd.precio_costo_unitario from compras_detalle as cd inner join compras as c on cd.idcompra = c.idcompras  left outer join productos as p on cd.idproducto = p.idproductos where cd.idcompra = " + idcompra;

			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "  |  " << fila[1] << "  |  " << fila[2] << "  |  " << fila[3] << "  |  " << fila[4] << "  |  " << fila[5] << endl;
				}

			}
			else {

				cout << "xxxxx error de  consulta xxxx" << endl;
			}
		}
		else {

			cout << " xxxxx error en la conexion xxxxx";
		}

		cn.cerrar_conexion();


	}


	

	void modificarComprasDetalle() {

		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string PRO = id_Producto;

		if (cn.getConectar()) {
			string id_Compras_Detalle;
			cout << " ingrese id a modificar :";
			cin >> id_Compras_Detalle;
			string update = " update ventas_detalle   set id_Producto='" + PRO + "', cantidad='" + cantidad + "', precio_costo_u='" + precio_costo_u + "', id_Compras='" + id_Compras + "' WHERE id_Ventas_Detalle= '" + id_Compras_Detalle + "'";
			const char* o = update.c_str();
			q_estado = mysql_query(cn.getConectar(), o);
			if (!q_estado) {
				cout << " modificacion Exitosa..." << endl;

			}
			else {

				cout << "xxxxx error de  modificacion xxxx" << endl;
			}

		}
		else {

			cout << " xxxxx error en la conexion xxxxx";
		}

		cn.cerrar_conexion();
	}

	void eliminarComprasDetalle() {

		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id_Compras_Detalle;
			cout << " ingrese id a eliminar :";
			cin >> id_Compras_Detalle;
			string sel = " DELETE FROM compras   WHERE id_Compras_Detalle= '" + id_Compras_Detalle + "'";
			const char* u = sel.c_str();
			q_estado = mysql_query(cn.getConectar(), u);
			if (!q_estado) {
				cout << " eliminacion exitosa ..." << endl;

			}
			else {

				cout << "xxxxx error al eliminar xxxx" << endl;
			}





		}
		else {

			cout << " xxxxx error en la conexion xxxxx";
		}

		cn.cerrar_conexion();



	}

	void eliminarT() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id_Compras;
			cout << " ingrese id a eliminar :";
			cin >> id_Compras;
			string sel = " DELETE FROM compras  WHERE id_Compras= '" + id_Compras + "'";
			const char* u = sel.c_str();
			q_estado = mysql_query(cn.getConectar(), u);
			if (!q_estado) {
				cout << " eliminacion exitosa ..." << endl;

			}
			else {

				cout << "xxxxx error al eliminar xxxx" << endl;
			}
		}



	}
};