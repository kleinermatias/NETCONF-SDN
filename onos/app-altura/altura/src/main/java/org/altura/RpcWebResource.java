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
import org.onosproject.incubator.net.faultmanagement.alarm.*;
import org.onosproject.net.DeviceId;
import org.onosproject.net.behaviour.MxpConfig;
import org.onosproject.net.driver.DriverHandler;
import org.onosproject.net.driver.DriverService;
import org.onosproject.rest.AbstractWebResource;
import javax.ws.rs.PUT;
import javax.ws.rs.Path;
import javax.ws.rs.PathParam;
import javax.ws.rs.Consumes;
import javax.ws.rs.Produces;
import javax.ws.rs.core.Response;
import javax.ws.rs.core.MediaType;
import java.util.ArrayList;
import java.util.List;


/**
 * Diferentes RPC disponibles a ejecutar en MXP40GB
 */
@Path("RPC")
public class RpcWebResource extends AbstractWebResource {

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



        List<Alarm> alarms = new ArrayList<>();
        alarms.add(new DefaultAlarm.Builder(AlarmId.alarmId(deviceId, "WARNING CONFIG"),
                deviceId, "[ALARM] mux-notify xmlns; ssssssssssssssss",
                Alarm.SeverityLevel.MINOR,
                System.currentTimeMillis()).build());
        providerService.updateAlarmList(deviceId,alarms);


        ObjectNode node = mapper().createObjectNode().put("rpcApplyConfig:", reply);
        return ok(node).build();

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



}






