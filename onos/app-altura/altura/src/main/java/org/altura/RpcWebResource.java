/*
 * Copyright 2018-present Open Networking Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package org.altura;

import com.fasterxml.jackson.databind.node.ObjectNode;
import com.google.common.collect.Iterables;
import org.apache.commons.lang.StringUtils;
import org.apache.felix.scr.annotations.Reference;
import org.apache.felix.scr.annotations.ReferenceCardinality;
import org.onosproject.incubator.net.faultmanagement.alarm.*;
import org.onosproject.net.Device;
import org.onosproject.net.DeviceId;
import org.onosproject.net.behaviour.MxpConfig;
import org.onosproject.net.behaviour.MxpGetAll;
import org.onosproject.net.device.DeviceService;
import org.onosproject.net.driver.DriverHandler;
import org.onosproject.net.driver.DriverService;
import org.onosproject.rest.AbstractWebResource;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import javax.ws.rs.PUT;
import javax.ws.rs.Path;
import javax.ws.rs.PathParam;
import javax.ws.rs.Consumes;
import javax.ws.rs.Produces;
import javax.ws.rs.Path;
import javax.ws.rs.PathParam;
import javax.ws.rs.core.Response;

import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;
import java.util.ArrayList;
import java.util.Collection;
import java.util.ListIterator;

/**
 * Diferentes RPC disponibles a ejecutar en MXP40GB
 */
@Path("RPC")
public class RpcWebResource extends AbstractWebResource {


    @Reference(cardinality = ReferenceCardinality.MANDATORY_UNARY)
    protected AlarmProviderService providerService;





    /**
     * Aplica la configuracion en el MXP40GB.
     *
     * @return 200 OK
     */
    @PUT
    @Path("Apply Config/{uri}")
    @Consumes(MediaType.APPLICATION_JSON)
    @Produces(MediaType.APPLICATION_JSON)
    public Response rpcApplyConfig(@PathParam("uri") String uri) {

        DriverService service = get(DriverService.class);
        DeviceId deviceId = DeviceId.deviceId(uri);
        DriverHandler h = service.createHandler(deviceId);
        MxpConfig mxp = h.behaviour(MxpConfig.class);
        String reply = mxp.rpcApplyConfig();

        Collection<Alarm> alarms = new ArrayList<>();
        alarms.add(new DefaultAlarm.Builder(AlarmId.alarmId(deviceId, "WARNING CONFIG"),
                deviceId, "[ALARM] mux-notify xmlns; Inconsistent config with neighbor ",
                Alarm.SeverityLevel.MINOR,
                System.currentTimeMillis()).build());

        providerService.updateAlarmList(deviceId,alarms);


        ObjectNode node = mapper().createObjectNode().put("rpcApplyConfig:", reply);
        return ok(node).build();

        /**

         DriverService service = get(DriverService.class);
         DeviceId deviceId = DeviceId.deviceId(uri);
         DriverHandler local_device = service.createHandler(deviceId);
         MxpConfig local_mxp = local_device.behaviour(MxpConfig.class);
         MxpGetAll local_mxp_get = local_device.behaviour(MxpGetAll.class);
         DeviceService deviceService = get(DeviceService.class);
         String reply = local_mxp.rpcApplyConfig();





         String local_config = local_mxp_get.getConfigContainer();
         ArrayList<String> lista_vecinos = getVecino(local_config);

         if ( !lista_vecinos.isEmpty() ) {

         ListIterator<String> vecinosIterator = lista_vecinos.listIterator();

         whileIteratorVecinos: while ( vecinosIterator.hasNext() ) {

         String vecino = vecinosIterator.next();


         // Se busca en los dispositivos actualmente conectados si hay alguno con un numero de serie que coincida con el indicado por el dispositivo como vecino.

         com.google.common.base.Optional<Device> dev = Iterables.tryFind(
         deviceService.getAvailableDevices(),
         input -> input.serialNumber().equals(vecino));

         if (!dev.isPresent()) {
         log.info("Device with chassis ID {} does not exist");
         continue whileIteratorVecinos;
         }

         else {

         DriverHandler remote_device = service.createHandler(dev.get().id());
         MxpGetAll remote_mxp_get = remote_device.behaviour(MxpGetAll.class);
         String remote_config = remote_mxp_get.getConfigContainer();

         if (getTipoTrafico(local_config).equals(getTipoTrafico(remote_config))) {
         log.info("Config iguales, se elimina alarma del dispositivo");


         while (alarmService.getActiveAlarms(deviceId).iterator().hasNext()) {
         Alarm it = alarmService.getActiveAlarms(deviceId).iterator().next();
         if ( (it.id().toString().contains("WARNING CONFIG")) && (it.description().equals("[ALARM] mux-notify xmlns; Inconsistent config with neighbor "+vecino))){
         alarmService.remove(it.id());
         }
         }
         }

         else {
         log.info("Config distintas, se crea alarma en el dispositivo");

         Collection<Alarm> alarms = new ArrayList<>();
         alarms.add(new DefaultAlarm.Builder(AlarmId.alarmId(deviceId, "WARNING CONFIG"),
         deviceId, "[ALARM] mux-notify xmlns; Inconsistent config with neighbor " + vecino,
         Alarm.SeverityLevel.MINOR,
         System.currentTimeMillis()).build());

         providerService.updateAlarmList(deviceId,alarms);
         }
         }
         }

         }
         else {

         }





         ObjectNode node = mapper().createObjectNode().put("rpcApplyConfig:", reply);
         return ok(node).build();

         **/

    }

    /**
     * Ejecuta comando -setting- en el MXP40GB.
     *
     * @return 200 OK
     */
    @PUT
    @Path("Apply Settings/{uri}")
    @Consumes(MediaType.APPLICATION_JSON)
    @Produces(MediaType.APPLICATION_JSON)
    public Response rpcSettingsConfig(@PathParam("uri") String uri) {
        DriverService service = get(DriverService.class);
        DeviceId deviceId = DeviceId.deviceId(uri);
        DriverHandler h = service.createHandler(deviceId);
        MxpConfig mxp = h.behaviour(MxpConfig.class);
        String reply = mxp.rpcSettingsConfig();
        ObjectNode node = mapper().createObjectNode().put("rpcSettingsConfig:", reply);
        return ok(node).build();
    }











    /**
     * Retrieving serial number version of device.
     * @return the serial number of the device
     */
    private ArrayList<String> getVecino(String config) {



        ArrayList<String> lista_vecinos = new ArrayList<String>();


        while (config.contains("neighbor")) {
            String vecino = StringUtils.substringBetween(config, "<neighbor>", "</neighbor>");
            config = config.replaceFirst("(?s)<neighbor>.*?</neighbor>", ""); // Borro el primer vecino encontrado. (?s) significa que se aplica a todas las lineas del string.
            lista_vecinos.add(vecino);
        }

        return lista_vecinos;
    }


    /**
     * Retrieving serial number version of device.
     * @param version the return of show version command
     * @return the serial number of the device
     */
    private String getTipoTrafico(String version) {


        String tipo_trafico = StringUtils.substringBetween(version, "<tipo_trafico>", "</tipo_trafico>");
        return tipo_trafico;
    }


}






