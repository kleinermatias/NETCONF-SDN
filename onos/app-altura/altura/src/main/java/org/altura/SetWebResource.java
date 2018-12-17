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
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;

/**
 * Setea datos de configuracion.
 */
@Path("SET")
public class SetWebResource extends AbstractWebResource {

    /**
     * setTimeToNotify in mxp.
     *
     * @return 200 OK
     */
    @PUT
    @Path("Time to Notify/{uri},{time_to_notify}")
    @Consumes(MediaType.APPLICATION_JSON)
    @Produces(MediaType.APPLICATION_JSON)
    public Response setTimeToNotify(@PathParam("uri") String uri, @PathParam("time_to_notify") String time_to_notify) {
        DriverService service = get(DriverService.class);
        DeviceId deviceId = DeviceId.deviceId(uri);
        DriverHandler h = service.createHandler(deviceId);
        MxpConfig mxp = h.behaviour(MxpConfig.class);
        String reply = mxp.setTimeToNotify(time_to_notify);
        ObjectNode node = mapper().createObjectNode().put("setTimeToNotify:", reply);
        return ok(node).build();
    }

    /**
     * setDeviceNeighbor in mxp.
     *
     * @return 200 OK
     */
    @PUT
    @Path("Neighbor/{uri},{Neighbor}")
    @Consumes(MediaType.APPLICATION_JSON)
    @Produces(MediaType.APPLICATION_JSON)
    public Response setDeviceNeighbors(@PathParam("uri") String uri, @PathParam("Neighbor") String Neighbor) {
        DriverService service = get(DriverService.class);
        DeviceId deviceId = DeviceId.deviceId(uri);
        DriverHandler h = service.createHandler(deviceId);
        MxpConfig mxp = h.behaviour(MxpConfig.class);
        String reply = mxp.setDeviceNeighbors(Neighbor);
        ObjectNode node = mapper().createObjectNode().put("setDeviceNeighbors:", reply);
        return ok(node).build();
    }

    /**
     * Setea tipo fec cliente.
     *
     * @return 200 OK
     */
    @PUT
    @Path("Tipo Fec de Cliente/{uri},{TIPO_FEC_CLIENTE}")
    @Consumes(MediaType.APPLICATION_JSON)
    @Produces(MediaType.APPLICATION_JSON)
    public Response setTipoFecCliente(@PathParam("uri") String uri, @PathParam("TIPO_FEC_CLIENTE") String TIPO_FEC_CLIENTE) {
        DriverService service = get(DriverService.class);
        DeviceId deviceId = DeviceId.deviceId(uri);
        DriverHandler h = service.createHandler(deviceId);
        MxpConfig mxp = h.behaviour(MxpConfig.class);
        String reply = mxp.setTipoFecCliente(TIPO_FEC_CLIENTE);
        ObjectNode node = mapper().createObjectNode().put("setTipoFecCliente:", reply);
        return ok(node).build();
    }

    /**
     * Setea tipo fec linea.
     *
     * @return 200 OK
     */
    @PUT
    @Path("Tipo Fec de linea/{uri},{TIPO_FEC_LINEA}")
    @Consumes(MediaType.APPLICATION_JSON)
    @Produces(MediaType.APPLICATION_JSON)
    public Response setTipoFecLinea(@PathParam("uri") String uri, @PathParam("TIPO_FEC_LINEA") String TIPO_FEC_LINEA) {
        DriverService service = get(DriverService.class);
        DeviceId deviceId = DeviceId.deviceId(uri);
        DriverHandler h = service.createHandler(deviceId);
        MxpConfig mxp = h.behaviour(MxpConfig.class);
        String reply = mxp.setTipoFecLinea(TIPO_FEC_LINEA);
        ObjectNode node = mapper().createObjectNode().put("setTipoFecLinea:", reply);
        return ok(node).build();
    }

    /**
     * Setea tipo trafico.
     *
     * @return 200 OK
     */
    @PUT
    @Path("Tipo de Trafico/{uri},{TIPO_TRAFICO}")
    @Consumes(MediaType.APPLICATION_JSON)
    @Produces(MediaType.APPLICATION_JSON)
    public Response setTipoTrafico(@PathParam("uri") String uri, @PathParam("TIPO_TRAFICO") String TIPO_TRAFICO) {
        DriverService service = get(DriverService.class);
        DeviceId deviceId = DeviceId.deviceId(uri);
        DriverHandler h = service.createHandler(deviceId);
        MxpConfig mxp = h.behaviour(MxpConfig.class);
        String reply = mxp.setTipoTrafico(TIPO_TRAFICO);
        ObjectNode node = mapper().createObjectNode().put("setTipoTrafico:", reply);
        return ok(node).build();
    }

}






