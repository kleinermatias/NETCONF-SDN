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

/**
 * Sample web resource.
 */
@Path("altura-api")
public class AppWebResource extends AbstractWebResource {

    /**
     * Get all data in mxp.
     *
     * @return 200 OK
     */
    @GET
    @Path("getAll/{uri}")
    public Response getAll(@PathParam("uri") String uri) {
        DriverService service = get(DriverService.class);
        Iterable<Device> devices = get(DeviceService.class).getDevices();
        String reply = null;


        DeviceId deviceId = DeviceId.deviceId(uri);
        DriverHandler h = service.createHandler(deviceId);
        MxpGetAll mxp = h.behaviour(MxpGetAll.class);
        reply = mxp.getAll();

        ObjectNode node = mapper().createObjectNode().put("getAll:", reply);
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


    /**
     * setValueEdfaNotify in mxp.
     *
     * @return 200 OK
     */
    @GET
    @Path("setValueEdfaNotify/{uri},{value_notify_config}")
    public Response setValueEdfaNotify(@PathParam("uri") String uri, @PathParam("value_notify_config") String value_notify_config) {
        DriverService service = get(DriverService.class);
        DeviceId deviceId = DeviceId.deviceId(uri);
        DriverHandler h = service.createHandler(deviceId);
        MxpConfig mxp = h.behaviour(MxpConfig.class);
        String reply = mxp.setValueEdfaNotify(value_notify_config);
        ObjectNode node = mapper().createObjectNode().put("setValueEdfaNotify:", reply);
        return ok(node).build();
    }

    /**
     * setEdfaOutPower in mxp.
     *
     * @return 200 OK
     */
    @GET
    @Path("setEdfaOutPower/{uri},{edfa_output_power}")
    public Response setEdfaOutPower(@PathParam("uri") String uri, @PathParam("edfa_output_power") String edfa_output_power) {
        DriverService service = get(DriverService.class);
        DeviceId deviceId = DeviceId.deviceId(uri);
        DriverHandler h = service.createHandler(deviceId);
        MxpConfig mxp = h.behaviour(MxpConfig.class);
        String reply = mxp.setValueEdfaNotify(edfa_output_power);
        ObjectNode node = mapper().createObjectNode().put("setEdfaOutPower:", reply);
        return ok(node).build();
    }

}






