
package pe.edu.pucp.parcial.db;

/**
 *
 * @author AXEL
 */
public abstract class DBManagerFactory {
    public abstract DBManager crearDBManager(String host, int puerto,
            String esquema, String usuario, String password);
}
