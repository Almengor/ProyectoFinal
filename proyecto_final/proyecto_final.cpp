#include <mysql.h>
#include <time.h>
#include <iostream>
#include "empleados.h"
#include "ConexionBD.h"
#include "clientes.h"
#include "puestos.h"
#include "marcas.h"
#include "proveedores.h"
#include "productos.h"
#include "compras.h"
#include "detalle_compras.h"
#include "ventas.h"
#include "ventas_detalle.h"
#include "fechaactual.h"
#include <iomanip>
#include <ctime>
#include <sstream>
#include <chrono>
#define _CRT_SECURE_NO_WARNINGS



using namespace std;


void repetir() {
};


void opciones()
{
	system("cls");
	cout << "_______________ Opciones _______________" << endl;
	cout << "1. Leer registros" << endl;
	cout << "2. Insertar registros" << endl;
	cout << "3. Modificar registros" << endl;
	cout << "4. Eliminar registros" << endl;
}

void opcionescompra()
{
	system("cls");
	cout << "_______________ Opciones Compra _______________" << endl;
	cout << "1. Leer facturas" << endl;
	cout << "2. Insertar compra" << endl;
	cout << "3. Imprimir compra" << endl;
}

void opcionesventa()
{
	system("cls");
	cout << "_______________ Opciones Venta _______________" << endl;
	cout << "1. Leer facturas" << endl;
	cout << "2. Insertar venta" << endl;
	cout << "3. Imprimir venta" << endl;
}

void menu()
{
	string genero,  puesto, nombre, apellido, direccion, dpi, fecha_nacimiento, inicio_labores, fechaingreso, nit, correo_electronico, marca, proveedor, producto, descripcion, imagen, fecha_orden;
	int opcion, opcion2, idpuesto,  telefono, id_empleado, idclientes, idmarca, idproveedores, existencia, idproducto, no_orden_compra;
	//int cantidad, no_orden_compra, idcompra;
	double precio_costo, precio_venta;
	//double precio_costo_unitario;

	empleados e = empleados();
	puestos p = puestos();
	clientes c = clientes();
	marcas m = marcas();
	proveedores pro = proveedores();
	productos pd = productos();
	compras cp = compras();
	detalle_compras dc = detalle_compras();
	fechaactual f = fechaactual();
	ventas v = ventas();
	ventas_detalle vd = ventas_detalle();

	cout << "\n " << endl;
	cout << "	 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "	|             SUPERMERCADO 'ANTIGUA COLONIAL'              |" << endl;
	cout << "	|                      Menu de Tablas                      |" << endl;
	cout << "	 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\n " << endl;
	cout << "1. Tabla Puestos" << endl;
	cout << "2. Tabla Empleados" << endl;
	cout << "3. Tabla Clientes" << endl;
	cout << "4. Tabla Marcas" << endl;
	cout << "5. Tabla Proveedores" << endl;
	cout << "6. Tabla Productos" << endl;
	cout << "7. Tabla Compras" << endl;
	cout << "8. Tabla Ventas" << endl;
	cout << "\n\tingrese la tabla que desea: ";
	cin >> opcion;
	cin.ignore();
	//PUESTOS
	if (opcion == 1)
	{
		system("cls");
		cout << "_______________ TABLA DE PUESTOS _______________" << endl;
		opciones();
		cout << "ingrese la opcion que desea: ";
		cin >> opcion2;
		cin.ignore();
		switch (opcion2)
		{
		case 1:
			system("cls");
			p.leer_puestos();
			repetir();
			break;
		case 2:
			system("cls");
			cout << "ingrese el puesto: ";
			getline(cin, puesto);
			p = puestos(puesto);
			p.insert_puestos();
			repetir();
			break;
		case 3:
			system("cls");
			p.leer_puestos();
			cout << endl << endl;
			cout << "ingrese el id del registro a modificar: ";
			cin >> idpuesto;
			cin.ignore();
			cout << "ingrese el nuevo puesto: ";
			getline(cin, puesto);
			p = puestos(puesto);
			p.update_puestos(idpuesto);
			repetir();
			break;
		case 4:
			system("cls");
			p.leer_puestos();
			cout << endl << endl;
			cout << "ingrese el id del registro a eliminar: ";
			cin >> idpuesto;
			cin.ignore();
			p.eliminar_puestos(idpuesto);
			repetir();
			break;
		}
	}

	/**********************************************************************************/
	//EMPLEADOS
	if (opcion == 2)
	{
		system("cls");
		cout << "_______________ TABLA DE PUESTOS _______________" << endl;
		opciones();
		cout << "ingrese la opcion que desea: ";
		cin >> opcion2;
		cin.ignore();
		switch (opcion2)
		{
		case 1:
			system("cls");
			e.leer_empleados();
			repetir();
			break;

		case 2:
			system("cls");
			cout << "\nIngrese nombres: ";
			getline(cin, nombre);
			cout << "\nIngrese apellidos: ";
			getline(cin, apellido);
			cout << "\nIngrese direccion: ";
			getline(cin, direccion);
			cout << "\nIngrese telefono: ";
			cin >> telefono;
			cin.ignore();
			cout << "\nIngrese DPI:";
			getline(cin, dpi);
			cout << "\ningrese Genero (F= mujer, M= hombre): ";
			cin >> genero;
			cin.ignore();
			cout << "\nIngrese fecha de nacimiento: ";
			getline(cin, fecha_nacimiento);
			cout << "\nIngrese id_puesto:";
			cin >> idpuesto;
			cin.ignore();
			cout << "\nIngrese fecha inicio labores: ";
			getline(cin, inicio_labores);
			cout << endl;
			cout << "\Fecha de ingreso: ";
			fechaingreso =  f.time_stamp();
			std::cout << f.time_stamp() << endl;
			cout << endl;
			cout << "\Presione cualquier tecla para continuar: ";
			cout << endl;
			getchar();
			//getline(cin, fechaingreso);

			e = empleados(nombre, apellido, direccion, telefono, dpi, genero, fecha_nacimiento, idpuesto, inicio_labores, fechaingreso);
			e.insert_empleados();
			repetir();
			break;

		case 3:
			system("cls");
			e.leer_empleados();
			cout << endl << endl;
			cout << "ingrese id empleado del registro a modificar: "; cin >> id_empleado;
			opcion2 = e.datos_modificar();
			switch (opcion2)
			{
			case 1:
				cout << "\ningrese el nuevo nombre: "; getline(cin, nombre);
				e.setnombres(nombre);
				break;
			case 2:
				cout << "\ningrese el nuevo apellido: "; getline(cin, apellido);
				e.setapellidos(apellido);
				break;
			case 3:
				cout << "\ningrese la nueva direccion: "; getline(cin, direccion);
				e.setdireccion(direccion);
				break;
			case 4:
				cout << "\ningrese el nuevo telefono: "; cin >> telefono; cin.ignore();
				e.settelefono(telefono);
				break;
			case 5:
				cout << "\ningrese el nuevo dpi: "; getline(cin, dpi);
				e.setdpi(dpi);
				break;
			case 6:
				cout << "\ningrese el nuevo genero  (F= mujer, M= hombre): "; cin >> genero; cin.ignore();
				e.setgenero(genero);
				break;
			case 7:
				cout << "\ningrese la nueva fecha de nacimiento "; getline(cin, fecha_nacimiento);
				e.setfechanacimiento(fecha_nacimiento);
				break;
			case 8:
				cout << "\ningrese el nuevo id puesto "; cin >> idpuesto; cin.ignore();
				e.setidpuesto(idpuesto);
				break;
			case 9:
				cout << "\ningrese la nueva fecha de inicio de labores "; getline(cin, inicio_labores);
				e.setiniciolabores(inicio_labores);
				break;
			case 10:
				/*cout << "\ningrese la nueva fecha de ingreso (anio/mes/dia hora:minuto:segundo): "; getline(cin, fechaingreso);
				e.setfechaingreso(fechaingreso);*/
				break;
			}
			e.update_empleados(opcion2, id_empleado);
			repetir();
			break;

		case 4:
			system("cls");
			e.leer_empleados();
			cout << endl << endl;
			cout << "ingrese el id empleado del registro que desea eliminar: "; cin >> id_empleado;
			e.eliminar_empleados(id_empleado);
			repetir();
			break;
		}
	}

	/**********************************************************************************/
	//CLIENTES
	if (opcion == 3)
	{
		system("cls");
		cout << "_______________ TABLA DE Clientes _______________" << endl;
		opciones();
		cout << "ingrese la opcion que desea: ";
		cin >> opcion2;
		cin.ignore();
		switch (opcion2)
		{
		case 1:
			system("cls");
			c.leer_clientes();
			repetir();
			break;
		case 2:

			system("cls");
			cout << "\nIngrese nombres: ";
			getline(cin, nombre);
			cout << "\nIngrese apellidos: ";
			getline(cin, apellido);
			cout << "\nIngrese nit: ";
			getline(cin, nit);
			cout << "\nIngrese genero (F = mujer, M = hombre): ";
			cin >> genero;
			cin.ignore();
			cout << "\nIngrese telefono:";
			cin >> telefono;
			cin.ignore();
			cout << "\nIngrese correo electronico: ";
			getline(cin, correo_electronico);
			/*cout << "\nIngrese fecha de ingreso (anio/mes/dia hora:minuto:segundo) ";
			getline(cin, fechaingreso);*/
			cout << endl;
			cout << "\Fecha de ingreso: ";
			fechaingreso = f.time_stamp();
			std::cout << f.time_stamp() << endl;
			cout << endl;
			cout << "\Presione cualquier tecla para continuar: ";
			cout << endl;
			getchar();

			c = clientes(nombre, apellido, nit, genero, telefono, correo_electronico, fechaingreso);
			c.insert_clientes();
			repetir();
			break;

		case 3:
			system("cls");
			c.leer_clientes();
			cout << endl << endl;
			cout << "ingrese id cliente del registro a modificar: "; cin >> idclientes;
			opcion2 = c.datos_modificar();
			switch (opcion2)
			{
			case 1:
				cout << "\ningrese el nuevo nombre: "; getline(cin, nombre);
				c.setnombres(nombre);
				break;
			case 2:
				cout << "\ningrese el nuevo apellido: "; getline(cin, apellido);
				c.setapellidos(apellido);
				break;
			case 3:
				cout << "\ningrese el nuevo nit: "; getline(cin, nit);
				c.setnit(nit);
				break;
			case 4:
				cout << "\ningrese el nuevo genero (F= mujer, M= hombre): "; cin >> genero; cin.ignore();
				c.setgenero(genero);
				break;
			case 5:
				cout << "\ningrese el nuevo telefono: "; cin >> telefono; cin.ignore();
				c.settelefono(telefono);
				break;
			case 6:
				cout << "\ningrese el nuevo correo electronico: "; getline(cin, correo_electronico);
				c.setcorreo_electronico(correo_electronico);
				break;
			case 7:
				/*cout << "\nFecha de ingreso: "; getline(cin, fechaingreso);
				c.setfechaingreso(fechaingreso);*/
				break;
			}
			c.update_clientes(opcion2, idclientes);
			repetir();

			break;
		case 4:
			system("cls");
			c.leer_clientes();
			cout << endl << endl;
			cout << "ingrese el id cliente del registro que desea eliminar: "; cin >> idclientes;
			c.eliminar_clientes(idclientes);
			repetir();
			break;
		}
	}

	/**********************************************************************************/

	//MARCAS
	if (opcion == 4)
	{
		system("cls");
		cout << "_______________ TABLA DE MARCAS _______________" << endl;
		opciones();
		cout << "ingrese la opcion que desea: ";
		cin >> opcion2;
		cin.ignore();
		switch (opcion2)
		{
		case 1:
			system("cls");
			m.leer_marcas();
			repetir();
			break;
		case 2:
			system("cls");
			cout << "ingrese la marca: ";
			getline(cin, marca);
			m = marcas(marca);
			m.insert_marcas();
			repetir();
			break;
		case 3:
			system("cls");
			m.leer_marcas();
			cout << endl << endl;
			cout << "ingrese el id del registro a modificar: ";
			cin >> idmarca;
			cin.ignore();
			cout << "ingrese la nueva marca: ";
			getline(cin, marca);
			m = marcas(marca);
			m.update_marcas(idmarca);
			repetir();
			break;
		case 4:
			system("cls");
			m.leer_marcas();
			cout << endl << endl;
			cout << "ingrese el id del registro a eliminar: ";
			cin >> idmarca;
			cin.ignore();
			m.eliminar_marcas(idmarca);
			repetir();
			break;
		}
	}

	/**********************************************************************************/

	//PROVEEDORES
	if (opcion == 5)
	{
		system("cls");
		cout << "_______________ TABLA DE PROVEEDORES _______________" << endl;
		opciones();
		cout << "ingrese la opcion que desea: ";
		cin >> opcion2;
		cin.ignore();
		switch (opcion2)
		{
		case 1:
			system("cls");
			pro.leer_proveedores();
			repetir();
			break;
		case 2:
			system("cls");
			cout << "\nIngrese proveedor: ";
			getline(cin, proveedor);
			cout << "\nIngrese nit: ";
			getline(cin, nit);
			cout << "\nIngrese direccion: ";
			getline(cin, direccion);
			cout << "\nIngrese telefono: ";
			cin >> telefono;
			cin.ignore();

			pro = proveedores(proveedor, nit, direccion, telefono);
			pro.insert_proveedores();
			repetir();
			break;
		case 3:

			system("cls");
			pro.leer_proveedores();
			cout << endl << endl;
			cout << "ingrese id proveedor del registro a modificar: "; cin >> idproveedores;
			opcion2 = pro.datos_modificar();
			switch (opcion2)
			{
			case 1:
				cout << "\ningrese el nuevo proveedor: "; getline(cin, proveedor);
				pro.setproveedor(proveedor);
				break;
			case 2:
				cout << "\ningrese el nuevo nit: "; getline(cin, nit);
				pro.setnit(nit);
				break;
			case 3:
				cout << "\ningrese la nueva direccion: "; getline(cin, direccion);
				pro.setdireccion(direccion);
				break;
			case 4:
				cout << "\ningrese el nuevo telefono: "; cin >> telefono; cin.ignore();
				pro.settelefono(telefono);
				break;
			}
			pro.update_proveedores(opcion2, idproveedores);
			repetir();

			break;
		case 4:
			system("cls");
			pro.leer_proveedores();
			cout << endl << endl;
			cout << "ingrese el id proveedor del registro que desea eliminar: "; cin >> idproveedores;
			pro.eliminar_proveedores(idproveedores);
			repetir();
			break;
		}
	}

	/**********************************************************************************/
	
	//PRODUCTOS
	if (opcion == 6)
	{
		system("cls");
		cout << "_______________ TABLA DE PRODUCTOS _______________" << endl;
		opciones();
		cout << "ingrese la opcion que desea: ";
		cin >> opcion2;
		cin.ignore();
		switch (opcion2)
		{
		case 1:
			system("cls");
			pd.leer_productos();
			repetir();
			break;
		case 2:
			system("cls");
			cout << "\nIngrese producto: ";
			getline(cin, producto);
			cout << "\nIngrese idmarca: ";
			cin >> idmarca;	cin.ignore();
			cout << "\nIngrese descripcion: ";
			getline(cin, descripcion);
			cout << "\nIngrese imagen: ";
			getline(cin, imagen);
			cout << "\ningrese Precio Costo: ";
			cin >> precio_costo;	cin.ignore();
			cout << "\nIngrese Precio Venta: ";
			cin >> precio_venta;	cin.ignore();
			cout << "\nIngrese Existencias: ";
			cin >> existencia;	cin.ignore();
			/*cout << "\nIngrese Fecha de Ingreso (anio/mes/dia hora:minuto:segundo): ";
			getline(cin, fechaingreso);*/
			cout << endl;
			cout << "\Fecha de ingreso: ";
			fechaingreso = f.time_stamp();
			std::cout << f.time_stamp() << endl;
			cout << endl;
			cout << "\Presione cualquier tecla para continuar: ";
			cout << endl;
			getchar();

			

			pd = productos(producto, idmarca, descripcion, imagen, precio_costo, precio_venta, existencia, fechaingreso);
			pd.insert_producto();
			repetir();
			break;
		case 3:

			system("cls");
			pd.leer_productos();
			cout << endl << endl;
			cout << "ingrese id producto del registro a modificar: "; cin >> idproducto;
			opcion2 = pd.datos_modificar();
			switch (opcion2)
			{
			case 1:
				cout << "\ningrese el nuevo producto: "; getline(cin, producto);
				pd.setproducto(producto);
				break;
			case 2:
				cout << "\ningrese el nuevo idmarca "; cin >> idmarca;	cin.ignore();
				pd.setidmarca(idmarca);
				break;
			case 3:
				cout << "\ningrese la nueva descripcion: "; getline(cin, descripcion);
				pd.setdescripcion(descripcion);
				break;
			case 4:
				cout << "\ningrese la nueva imagen: "; getline(cin, imagen);
				pd.setimagen(imagen);
				break;
			case 5:
				cout << "\ningrese el nuevo precio costo: "; cin >> precio_costo; cin.ignore();
				pd.setprecio_costo(precio_costo);
				break;
			case 6:
				cout << "\ningrese el nuevo precio venta: "; cin >> precio_venta; cin.ignore();
				pd.setprecio_venta(precio_venta);
				break;
			case 7:
				cout << "\ningrese la nueva cantidad de existencias: "; cin >> existencia; cin.ignore();
				pd.setexistencias(existencia);
				break;
			case 8:
				/*cout << "\ningrese la nueva fecha de ingreso (anio/mes/dia hora:minuto:segundo): "; getline(cin, fechaingreso);
				pd.setfecha_ingreso(fechaingreso);*/
				break;
			}
			pd.update_productos(opcion2, idproducto);
			repetir();

			break;
		case 4:
			system("cls");
			pd.leer_productos();
			cout << endl << endl;
			cout << "ingrese el id producto del registro que desea eliminar: "; cin >> idproducto;
			pd.eliminar_productos(idproducto);
			repetir();
			break;
		}
	}

	/**********************************************************************************/

	//COMPRAS
	if (opcion == 7)
	{
		system("cls");
		cout << "_______________ TABLA DE COMPRAS  _______________" << endl;
		opcionescompra();
		cout << "ingrese la opcion que desea: ";
		cin >> opcion2;
		cin.ignore();
		string idempleado = "";
		string nitproveedor = "";
		string idproveedor = "";
		string idproducto = "";
		string cantidad = "";
		string precio_costo_unitario = "";
		string res = "";
		string idcompra = "";
		switch (opcion2)
		{
		case 1:
			system("cls");
			cp.leer_compras();
			repetir();
			break;
		case 2:
			system("cls");

			cout << endl << endl;
			cout << "Ingrese el id del empleado: "; cin >> idempleado;
			e.consultar_empleado(idempleado);

			cout << endl << endl;
			cout << "Ingrese nit del proveedor: "; cin >> nitproveedor;
			pro.consultar_proveedor(nitproveedor);
			idproveedor = pro.consultar_proveedorid(nitproveedor);

			cout << "\nId proveedor: ";
			std::cout << idproveedor << endl;

			cout << "\Fecha de orden: ";
			fechaingreso = f.time_stamp();
			std::cout << f.time_stamp() << endl;
			
			cout << "\Fecha de ingreso:  ";
			fechaingreso = f.time_stamp();
			std::cout << f.time_stamp() << endl;

			cout << "Ingrese no de orden:     "; cin >> no_orden_compra;
			cout << endl;

			cp = compras(no_orden_compra, fechaingreso, idproveedor, fechaingreso);
			cp.insert_compras();
			cp.consulta_comprasnoorden(to_string(no_orden_compra));
			idcompra = cp.consulta_comprasid(to_string(no_orden_compra));
			do {

				cout << " Detalle compra \n" << endl;
				cout << " Ingrese id producto\n" << endl;
				cin >> idproducto;	cin.ignore();
				cout << " ingrese cantidad : " << endl;
				cin >> cantidad;	cin.ignore();
				cout << " ingrese precio costo unitario:  " << endl;
				cin >> precio_costo_unitario;	cin.ignore();

				dc = detalle_compras(idcompra, idproducto, cantidad, precio_costo_unitario);
				dc.crearComprasDetalle();
				
				cout << " Desesa ingresar nuevamente? [s/n]" << endl;
				cin >> res;
			} 
			while (res == "s");
			dc.leerComprasDetalle(idcompra);
			repetir();
			break;

		case 3:
			system("cls");
			int imprimir = 0;
			string ordencompra = "";
			cout << endl << endl;
			cout << "Ingrese el numero de orden de compra: "; cin >> ordencompra;
			cp.imprimir_compras(ordencompra);
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "Ingrese 1 para imprimir: "; cin >> imprimir;
			cout << endl;
			cout << "\Presione cualquier tecla para continuar: ";
			cout << endl;
			getchar();
			repetir();
			break;
		}
	}

	/*if (opcion == 7)
	{
		system("cls");
		switch (opcion) {
		case 1: {
			compras c = compras();
			detalle_compras cd = detalle_compras();
			productos pr = productos();
			proveedores pro = proveedores();
			
			int res;
			cout << " para ingresar......." << endl;
			int variable = 0;
			string fecha_orden, fecha_ingreso, cantidad, precio_costo_u, id_Compras;
			int no_orden_compra = 0;
			int id_proveedor = 0;
			int id_Producto = 0;

			if (no_orden_compra == 100) {
				no_orden_compra = 0;
				variable++;
			}
			cin.ignore();
			no_orden_compra++;
			cin.ignore();
			cout << " numero de orden de compra: " << endl;
			cout << no_orden_compra;
			cout << " ingrese id de proveedor : " << endl;
			cin >> id_proveedor;
			cout << " ingrese fecha orden : " << endl;
			cin >> fecha_ingreso;
			c.leer_compras();
			cout << " ingrese fecha ingreso : " << endl;
			cin >> fecha_ingreso;
			c.leer_compras();
			cin.ignore();
			c.insert_compras();

			do {

				cout << " Detalles.......\n" << endl;

				cout << " ingrese cantidad : " << endl;
				cin >> cantidad;
				cin.ignore();
				cout << " ingrese precio costo unitario:  " << endl;
				cin >> precio_costo_u;
				cin.ignore();

				cout << " Desesa ingresar nuevamente? [s/n]" << endl;
				cin >> res;
			} while (res == 's');

			id_Compras = c.asignar(no_orden_compra);
			cd = detalle_compras();
			cd.crearComprasDetalle();

			system("pause");
			system("cls");
			break;
		}
		case 2: {
			compras c = compras();
			detalle_compras cd = detalle_compras();
			c.leer_compras();
			cd.leerComprasDetalle();
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			cout << " para modificar......." << endl;
			string fecha_orden, fecha_ingreso, cantidad, precio_costo_u, id_Compras;
			int no_orden_compra = 0;
			int id_proveedor = 0;
			int id_Producto = 0;

			cout << " ingrese numero de orden de compra: " << endl;
			cin >> no_orden_compra;
			cout << " ingrese Fecha orden: " << endl;
			cin >> fecha_orden;
			cout << " ingrese fecha ingreso: " << endl;
			cin >> fecha_ingreso;
			cout << " ingrese cantidad :" << endl;
			cin >> cantidad;
			cout << " ingrese precio costo unitario : " << endl;
			cin >> precio_costo_u;
			cout << " ingrese id Proveedor : " << endl;
			cin >> id_proveedor;
			cout << " ingrese id del producto : " << endl;
			cin >> id_Producto;
			cin.ignore();
			break;
		}
		case 4: {
			compras c = compras();
			detalle_compras cd = detalle_compras();
			c.eliminar_compras();
			cd.eliminarComprasDetalle();
			cd.eliminarT();
			system("pause");
			system("cls");
			break;

		}
		case 0: {
			menu();
			system("pause>nul");
			break;

		}

		}
	}*/

	/**********************************************************************************/
	
	//VENTAS
	if (opcion == 8)
	{
		system("cls");
		cout << "_______________ TABLA DE VENTAS  _______________" << endl;
		opcionesventa();
		cout << "ingrese la opcion que desea: ";
		cin >> opcion2;
		cin.ignore();
		string idempleado = "";
		string nitcliente = "";
		string idcliente = "";
		string idproducto = "";
		string cantidad = "";
		string precio_costo_unitario = "";
		string res = "";
		string idventa = "";
		string nofactura = "";
		string serie = "1";
		switch (opcion2)
		{
		case 1:
			system("cls");
			v.leerVentas();
			repetir();
			break;
		case 2:
			system("cls");

			cout << endl << endl;
			cout << "Ingrese el id del empleado: "; cin >> idempleado;
			e.consultar_empleado(idempleado);

			cout << endl << endl;
			cout << "Ingrese nit del cliente: "; cin >> nitcliente;
			c.consultar_cliente(nitcliente);
			idcliente = c.consultar_clienteid(nitcliente);

			cout << "\nId cliente: ";
			std::cout << idcliente << endl;

			cout << "\Fecha de orden: ";
			fechaingreso = f.time_stamp();
			std::cout << f.time_stamp() << endl;

			cout << "\Fecha de ingreso:  ";
			fechaingreso = f.time_stamp();
			std::cout << f.time_stamp() << endl;

			cout << "Ingrese no factura:     "; cin >> nofactura;
			cout << endl;
			
			v = ventas(nofactura,serie, fechaingreso, idcliente, idempleado,fechaingreso);
			v.crearVentas();
			v.consulta_ventasnofactura(nofactura);
			idventa = v.consulta_ventasid(nofactura);
			do {
				cout << endl;
				cout << " Detalle Venta \n" << endl;
				cout << " Ingrese id producto\n" << endl;
				cin >> idproducto;	cin.ignore();
				cout << " ingrese cantidad : " << endl;
				cin >> cantidad;	cin.ignore();
				cout << " ingrese precio costo unitario:  " << endl;
				cin >> precio_costo_unitario;	cin.ignore();

				vd = ventas_detalle(idventa, idproducto, cantidad, precio_costo_unitario);
				vd.crearVentaDetalle();

				cout << " Desesa ingresar nuevamente? [s/n]" << endl;
				cin >> res;
			} 			while (res == "s");
			vd.leerVentasDetalle(idventa);
			repetir();
			break;

		case 3:
			system("cls");
			int imprimir = 0;
			string nofactura = "";
			cout << endl << endl;
			cout << "Ingrese el numero de factura de venta: "; cin >> nofactura;
			v.imprimir_ventas(nofactura);
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "Ingrese 1 para imprimir: "; cin >> imprimir;
			cout << endl;
			cout << "\Presione cualquier tecla para continuar: ";
			cout << endl;
			getchar();
			repetir();
			break;
		}
	}

	/**********************************************************************************/

	void repetir();
	{
		string opc;
		cout << endl << endl << "Desea probar otra opcion (s/n): ";
		cin >> opc;
		cin.ignore();
		if (opc == "S" || opc == "s")
		{
			system("cls");
			menu();
		}
	}
}

//string currentDateTime() {
//	time_t now = time(0); 
//	struct tm tstruct; 
//	char buf[80]; 
//	tstruct = *localtime(&now); 
//	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct); 
//	return buf; 
//} 



int main()
{
	fechaactual f = fechaactual();
	//auto now = std::chrono::system_clock::now();
	//auto time = std::chrono::system_clock::to_time_t(now);

	//std::cout << std::put_time(std::localtime(&time), "%F %T") << endl;
	string mifecha = f.time_stamp();
	std::cout << endl;
	std::cout << f.time_stamp() << endl;
	menu();
}
