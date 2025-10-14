package pe.edu.pucp.parcial.db;

/**
 *
 * @author AXEL
 */
public class MSSQLDBManagerFactory extends DBManagerFactory {
    @Override
    public DBManager crearDBManager(String host,int puerto,String esquema,
            String usuario,String password){
        return MSSQLDBManager.getInstance(host,puerto,esquema,usuario,password);
    }
}
