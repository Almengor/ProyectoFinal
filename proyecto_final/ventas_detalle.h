#pragma once
#include "ventas.h"
#include <mysql.h>
#include <iostream>
#include"ConexionBD.h"
#include <string>

using namespace std;

class ventas_detalle {
	// atributos

	   // metodo constructor
protected: string cantidad, precio_uni, id_Ventas, id_Producto;
		 //int id_Producto = 0;
public:
	ventas_detalle() {
	}

	ventas_detalle(string vn, string pr,string cant, string unit)/* :venta(vn,nf,cant,unit,se,fft,idc,ide,ing,pr)*/ {
		id_Ventas = vn;
		id_Producto = pr;
		cantidad = cant;
		precio_uni = unit;
	}
	// metodos de modificar datos
	// set ( modificar)
	void setcantidad(string cant) { cantidad = cant; }
	void setprecio_unitario(string unit) { precio_uni = unit; }
	void setid_Producto(string pr) { id_Producto = pr; }
	void setid_Ventas(string vn) { id_Ventas = vn; }


	// get(mostrar)
	string getcantidad() { return cantidad; }
	string getprecio_unitario() { return precio_uni; }
	string getid_Producto() { return id_Producto; }
	string getid_Ventas() { return id_Ventas; }



	void crearVentaDetalle() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		string produc = id_Producto;
		//string vent = to_string(id_Ventas);
		cn.abrir_conexion();
		if (cn.getConectar()) {

			string insert = " insert into ventas_detalle(idventa,idproducto, cantidad, precio_unitario) VALUES (" + id_Ventas + "," + id_Producto + ",  " + cantidad + "," + precio_uni + ");";
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

	void leerVentaDetalle() {

		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {


			string consulta = "select * from  ventasdetalle ";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "----------------------------VentaDetalle------------------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[1] << "  |  " << fila[2] << "  |  " << fila[3] << endl;
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

	void leerVentasDetalle(string idventa) {

		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			cout << "\n" << endl;
			cout << "----------------------------DETALLE VENTA------------------------" << endl;
			cout << "\n" << endl;
			string consulta = "select vd.idventas_detalle, vd.idventa, vd.idproducto, pro.producto, vd.cantidad, vd.precio_unitario from ventas_detalle as vd left outer join productos as pro on vd.idproducto = pro.idproductos left outer join ventas as v on vd.idventa = v.idventas where vd.idventa = " + idventa;

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

	void modificarDetalle() {

		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string PR = id_Producto;

		if (cn.getConectar()) {
			string id_Ventas_Detalle;
			cout << " ingrese id a modificar :";
			cin >> id_Ventas_Detalle;
			string update = " update ventas_detalle   set id_Producto='" + PR + "', cantidad='" + cantidad + "', precio_uni='" + precio_uni + "', id_Ventas='" + id_Ventas + "' WHERE id_Ventas_Detalle= '" + id_Ventas_Detalle + "'";
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

	void eliminarDetalle() {

		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id_Ventas_Detalle;
			cout << " ingrese id a eliminar :";
			cin >> id_Ventas_Detalle;
			string sel = " DELETE FROM ventas   WHERE id_Ventas_Detalle= '" + id_Ventas_Detalle + "'";
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

	void eliminarDetalleT() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id_Ventas;
			cout << " ingrese id a eliminar :";
			cin >> id_Ventas;
			string sel = " DELETE FROM ventas   WHERE id_Ventas= '" + id_Ventas + "'";
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