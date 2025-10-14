package pe.edu.pucp.parcial.transitsoftmodelo;

import java.util.Date;

/**
 *
 * @author AXEL
 */
public class Captura {
    private Integer id;
    private String placa;
    private double velocidad;
    private Date fecha_captura;

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getPlaca() {
        return placa;
    }

    public void setPlaca(String placa) {
        this.placa = placa;
    }

    public double getVelocidad() {
        return velocidad;
    }

    public void setVelocidad(double velocidad) {
        this.velocidad = velocidad;
    }

    public Date getFecha_captura() {
        return fecha_captura;
    }

    public void setFecha_captura(Date fecha_captura) {
        this.fecha_captura = fecha_captura;
    }
    
    
}
