package pe.edu.pucp.parcial.transitsoftpersistencia.dao;

import java.sql.Connection;


/**
 *
 * @author AXEL
 */
public interface PersistibleTransaccional<T, I> extends Persistible<T, I> {
    I crear(T modelo, Connection conexion);
    boolean actualiza(T modelo, Connection conexion);
    boolean eliminar(I id, Connection conexion);
}
