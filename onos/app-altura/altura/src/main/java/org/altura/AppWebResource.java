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
import org.onosproject.rest.AbstractWebResource;

import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.PathParam;

import javax.ws.rs.core.Response;


import org.apache.karaf.shell.commands.Argument;
import org.apache.karaf.shell.commands.Command;
import org.onosproject.cli.AbstractShellCommand;
import org.onosproject.net.behaviour.MxpGetAll;
import org.onosproject.net.behaviour.MxpConfig;
import org.onosproject.net.behaviour.MxpLoadModule;
import org.onosproject.net.DeviceId;
import org.onosproject.net.driver.DriverHandler;
import org.onosproject.net.driver.DriverService;

import org.onosproject.net.Device;
import org.onosproject.net.device.DeviceService;

import static org.onlab.util.Tools.nullIsNotFound;

import org.json.JSONObject;
import org.json.XML;

/**
 * Obtiene datos de estado y configuracion de los diferentes container.
 */
@Path("GET")
public class AppWebResource extends AbstractWebResource {

    /**
     * Get all data in mxp.
     *
     * @return 200 OK
     */
    @GET
    @Path("ALL/{uri}")
    public Response getAll(@PathParam("uri") String uri) {
        DriverService service = get(DriverService.class);
        DeviceId deviceId = DeviceId.deviceId(uri);
        DriverHandler h = service.createHandler(deviceId);
        MxpGetAll mxp = h.behaviour(MxpGetAll.class);
        String reply = mxp.getAll();
        String text = reply.replace("\n", "").replace("\r", "");
        String m = text.replaceAll("\\s","");
        //JSONObject xmlJSONObj = XML.toJSONObject(m);
        ObjectNode node = mapper().createObjectNode().put("getAll:", m);
        return ok(node).build();
    }

    /**
     * Get config data in mxp.
     *
     * @return 200 OK
     */
    @GET
    @Path("Config Data/{uri}")
    public Response getConfigContainer(@PathParam("uri") String uri) {
        DriverService service = get(DriverService.class);
        DeviceId deviceId = DeviceId.deviceId(uri);
        DriverHandler h = service.createHandler(deviceId);
        MxpGetAll mxp = h.behaviour(MxpGetAll.class);
        String reply = mxp.getConfigContainer();
        ObjectNode node = mapper().createObjectNode().put("getConfigContainer:", reply);
        return ok(node).build();
    }

    /**
     * Get state container in mxp.
     *
     * @return 200 OK
     */
    @GET
    @Path("State Container/{uri}")
    public Response getStateContainer(@PathParam("uri") String uri) {
        DriverService service = get(DriverService.class);
        DeviceId deviceId = DeviceId.deviceId(uri);
        DriverHandler h = service.createHandler(deviceId);
        MxpGetAll mxp = h.behaviour(MxpGetAll.class);
        String reply = mxp.getStateContainer();
        ObjectNode node = mapper().createObjectNode().put("getStateContainer:", reply);
        return ok(node).build();
    }

    /**
     * Get state dsp container in mxp.
     *
     * @return 200 OK
     */
    @GET
    @Path("DSP Container/{uri}")
    public Response getDspContainer(@PathParam("uri") String uri) {
        DriverService service = get(DriverService.class);
        DeviceId deviceId = DeviceId.deviceId(uri);
        DriverHandler h = service.createHandler(deviceId);
        MxpGetAll mxp = h.behaviour(MxpGetAll.class);
        String reply = mxp.getDspContainer();
        ObjectNode node = mapper().createObjectNode().put("getDspContainer:", reply);
        return ok(node).build();
    }

    /**
     * Get state edfa container in mxp.
     *
     * @return 200 OK
     */
    @GET
    @Path("EDFA Container/{uri}")
    public Response getEdfaContainer(@PathParam("uri") String uri) {
        DriverService service = get(DriverService.class);
        DeviceId deviceId = DeviceId.deviceId(uri);
        DriverHandler h = service.createHandler(deviceId);
        MxpGetAll mxp = h.behaviour(MxpGetAll.class);
        String reply = mxp.getEdfaContainer();
        ObjectNode node = mapper().createObjectNode().put("getEdfaContainer:", reply);
        return ok(node).build();
    }

    /**
     * Get state misc container in mxp.
     *
     * @return 200 OK
     */
    @GET
    @Path("Misc Container/{uri}")
    public Response getStateMiscContainer(@PathParam("uri") String uri) {
        DriverService service = get(DriverService.class);
        DeviceId deviceId = DeviceId.deviceId(uri);
        DriverHandler h = service.createHandler(deviceId);
        MxpGetAll mxp = h.behaviour(MxpGetAll.class);
        String reply = mxp.getStateMiscContainer();
        ObjectNode node = mapper().createObjectNode().put("getStateMiscContainer:", reply);
        return ok(node).build();
    }

    /**
     * Get state temp/hum container in mxp.
     *
     * @return 200 OK
     */
    @GET
    @Path("Temp&Hum Container/{uri}")
    public Response getTempHumContainer(@PathParam("uri") String uri) {
        DriverService service = get(DriverService.class);
        DeviceId deviceId = DeviceId.deviceId(uri);
        DriverHandler h = service.createHandler(deviceId);
        MxpGetAll mxp = h.behaviour(MxpGetAll.class);
        String reply = mxp.getTempHumContainer();
        ObjectNode node = mapper().createObjectNode().put("getTempHumContainer:", reply);
        return ok(node).build();
    }

    /**
     * Get state power container in mxp.
     *
     * @return 200 OK
     */
    @GET
    @Path("Power Container/{uri}")
    public Response getStatePowerContainer(@PathParam("uri") String uri) {
        DriverService service = get(DriverService.class);
        DeviceId deviceId = DeviceId.deviceId(uri);
        DriverHandler h = service.createHandler(deviceId);
        MxpGetAll mxp = h.behaviour(MxpGetAll.class);
        String reply = mxp.getStatePowerContainer();
        ObjectNode node = mapper().createObjectNode().put("getStatePowerContainer:", reply);
        return ok(node).build();
    }

    /**
     * Get state tx/rx alarm container in mxp.
     *
     * @return 200 OK
     */
    @GET
    @Path("Tx&Rx Alarms Container/{uri}")
    public Response getStateTxRxAlarmContainer(@PathParam("uri") String uri) {
        DriverService service = get(DriverService.class);
        DeviceId deviceId = DeviceId.deviceId(uri);
        DriverHandler h = service.createHandler(deviceId);
        MxpGetAll mxp = h.behaviour(MxpGetAll.class);
        String reply = mxp.getStateTxRxAlarmContainer();
        ObjectNode node = mapper().createObjectNode().put("getStateTxRxAlarmContainer:", reply);
        return ok(node).build();
    }

    /**
     * Get state xfp1 container in mxp.
     *
     * @return 200 OK
     */
    @GET
    @Path("XFP1 Container/{uri}")
    public Response getXFPOneContainer(@PathParam("uri") String uri) {
        DriverService service = get(DriverService.class);
        DeviceId deviceId = DeviceId.deviceId(uri);
        DriverHandler h = service.createHandler(deviceId);
        MxpGetAll mxp = h.behaviour(MxpGetAll.class);
        String reply = mxp.getXFPOneContainer();
        ObjectNode node = mapper().createObjectNode().put("getXFPOneContainer:", reply);
        return ok(node).build();
    }

    /**
     * Get state xfp2 container in mxp.
     *
     * @return 200 OK
     */
    @GET
    @Path("XFP2 Container/{uri}")
    public Response getXFPTwoContainer(@PathParam("uri") String uri) {
        DriverService service = get(DriverService.class);
        DeviceId deviceId = DeviceId.deviceId(uri);
        DriverHandler h = service.createHandler(deviceId);
        MxpGetAll mxp = h.behaviour(MxpGetAll.class);
        String reply = mxp.getXFPTwoContainer();
        ObjectNode node = mapper().createObjectNode().put("getXFPTwoContainer:", reply);
        return ok(node).build();
    }

    /**
     * Get state xfp3 container in mxp.
     *
     * @return 200 OK
     */
    @GET
    @Path("XFP3 Container/{uri}")
    public Response getXFPThreeContainer(@PathParam("uri") String uri) {
        DriverService service = get(DriverService.class);
        DeviceId deviceId = DeviceId.deviceId(uri);
        DriverHandler h = service.createHandler(deviceId);
        MxpGetAll mxp = h.behaviour(MxpGetAll.class);
        String reply = mxp.getXFPThreeContainer();
        ObjectNode node = mapper().createObjectNode().put("getXFPThreeContainer:", reply);
        return ok(node).build();
    }

    /**
     * Get state xfp4 container in mxp.
     *
     * @return 200 OK
     */
    @GET
    @Path("XFP4 Container/{uri}")
    public Response getXFPFourContainer(@PathParam("uri") String uri) {
        DriverService service = get(DriverService.class);
        DeviceId deviceId = DeviceId.deviceId(uri);
        DriverHandler h = service.createHandler(deviceId);
        MxpGetAll mxp = h.behaviour(MxpGetAll.class);
        String reply = mxp.getXFPFourContainer();
        ObjectNode node = mapper().createObjectNode().put("getXFPFourContainer:", reply);
        return ok(node).build();
    }

    /**
     * Load module in mxp.
     *
     * @return 200 OK
     */
    @GET
    @Path("loadModule/{uri},{module}")
    public Response loadModule(@PathParam("uri") String uri, @PathParam("module") String module) {
        DriverService service = get(DriverService.class);
        DeviceId deviceId = DeviceId.deviceId(uri);
        DriverHandler h = service.createHandler(deviceId);
        MxpLoadModule mxp = h.behaviour(MxpLoadModule.class);
        String reply = mxp.loadModule(module);
        ObjectNode node = mapper().createObjectNode().put("loadModule:", reply);
        return ok(node).build();
    }

}






