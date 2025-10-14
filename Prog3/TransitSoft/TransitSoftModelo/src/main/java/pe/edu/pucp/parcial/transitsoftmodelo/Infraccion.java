package pe.edu.pucp.parcial.transitsoftmodelo;

import java.util.Date;

/**
 *
 * @author AXEL
 */
public class Infraccion {
    private Integer id;
    private Vehiculo vehiculo;
    private Propietario propietario;
    private Camara camara;
    private double monto;
    private Date fecha_captura;
    private Date fecha_registro;
    private double exceso;
    private double limite;
    private double velocidad;
    private String placa;

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public Vehiculo getVehiculo() {
        return vehiculo;
    }

    public void setVehiculo(Vehiculo vehiculo) {
        this.vehiculo = vehiculo;
    }

    public Propietario getPropietario() {
        return propietario;
    }

    public void setPropietario(Propietario propietario) {
        this.propietario = propietario;
    }

    public Camara getCamara() {
        return camara;
    }

    public void setCamara(Camara camara) {
        this.camara = camara;
    }

    public double getMonto() {
        return monto;
    }

    public void setMonto(double monto) {
        this.monto = monto;
    }

    public Date getFecha_captura() {
        return fecha_captura;
    }

    public void setFecha_captura(Date fecha_captura) {
        this.fecha_captura = fecha_captura;
    }

    public Date getFecha_registro() {
        return fecha_registro;
    }

    public void setFecha_registro(Date fecha_registro) {
        this.fecha_registro = fecha_registro;
    }

    public double getExceso() {
        return exceso;
    }

    public void setExceso(double exceso) {
        this.exceso = exceso;
    }

    public double getLimite() {
        return limite;
    }

    public void setLimite(double limite) {
        this.limite = limite;
    }

    public double getVelocidad() {
        return velocidad;
    }

    public void setVelocidad(double velocidad) {
        this.velocidad = velocidad;
    }

    public String getPlaca() {
        return placa;
    }

    public void setPlaca(String placa) {
        this.placa = placa;
    }
    
    
    
}
