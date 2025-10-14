package pe.edu.pucp.parcial.transitsoftpersistencia.dao;

import java.util.List;

/**
 *
 * @author AXEL
 */
public interface Persistible<T, I> {
    I crear(T modelo);
    boolean actualizar(T modelo);
    boolean eliminar(I id);
    T leer(I id);
    List<T> leerTodos();
}
