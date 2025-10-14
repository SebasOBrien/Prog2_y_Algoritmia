
package pe.edu.pucp.parcial.db;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import pe.edu.pucp.parcial.db.utils.TipoDB;

/**
 *
 * @author AXEL
 */
public class MSSQLDBManager extends DBManager {
    private static MSSQLDBManager instancia;
    
    protected MSSQLDBManager(){}
    
    protected MSSQLDBManager(String host, int puerto, String esquema,
            String usuario,String password){
        super(host,puerto,esquema,usuario,password,TipoDB.MSSQL);
    }
    
    static synchronized MSSQLDBManager getInstance(String host, int puerto,
            String esquema, String usuario, String password){
        if( instancia == null){
            instancia = new MSSQLDBManager(host, puerto, esquema, usuario, password);
        }
        return instancia;
    }
    
    @Override
    public Connection getConnection() throws SQLException,
            ClassNotFoundException{
        try{
            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            String cadenaConexion = cadenaConexion();
            return DriverManager.getConnection(cadenaConexion,usuario,password);
        }
        catch (ClassNotFoundException | SQLException e){
            System.err.println(e);
            throw e;
        }
    }
}
