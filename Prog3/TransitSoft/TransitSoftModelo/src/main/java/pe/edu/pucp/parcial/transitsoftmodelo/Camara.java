package pe.edu.pucp.parcial.transitsoftmodelo;

import java.util.List;

/**
 *
 * @author AXEL
 */
public class Camara {
    private Integer id;
    private String modelo;
    private String codigo_serie;
    private int latitud;
    private int longitud;
    private List<Captura> capturas;

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public String getCodigo_serie() {
        return codigo_serie;
    }

    public void setCodigo_serie(String codigo_serie) {
        this.codigo_serie = codigo_serie;
    }

    public int getLatitud() {
        return latitud;
    }

    public void setLatitud(int latitud) {
        this.latitud = latitud;
    }

    public int getLongitud() {
        return longitud;
    }

    public void setLongitud(int longitud) {
        this.longitud = longitud;
    }

    public List<Captura> getCapturas() {
        return capturas;
    }

    public void setCapturas(List<Captura> capturas) {
        this.capturas = capturas;
    }
    
}
