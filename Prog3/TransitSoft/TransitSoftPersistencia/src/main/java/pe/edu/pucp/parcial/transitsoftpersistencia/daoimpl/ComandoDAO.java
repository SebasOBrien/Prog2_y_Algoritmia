package pe.edu.pucp.parcial.transitsoftpersistencia.daoimpl;

import java.sql.Connection;
import java.sql.SQLException;

/**
 *
 * @author AXEL
 */
public interface ComandoDAO<R> {
    R ejecutar(Connection conn) throws SQLException;
}
