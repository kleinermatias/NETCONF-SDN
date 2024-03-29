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

import org.apache.felix.scr.annotations.*;
import org.onosproject.incubator.net.faultmanagement.alarm.AlarmEvent;
import org.onosproject.incubator.net.faultmanagement.alarm.AlarmListener;
import org.onosproject.net.Device;
import org.onosproject.net.device.DeviceService;
import org.onosproject.net.driver.DriverHandler;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;


import org.onosproject.incubator.net.faultmanagement.alarm.Alarm;
import org.onosproject.incubator.net.faultmanagement.alarm.AlarmService;
import org.onosproject.net.DeviceId;
import org.apache.commons.lang3.builder.ToStringBuilder;
import org.apache.commons.lang3.builder.ToStringStyle;
import java.util.Set;

/**
 * Skeletal ONOS application component.
 */
@Component(immediate = true)
public class AppComponent {

    @Reference(cardinality = ReferenceCardinality.MANDATORY_UNARY)
    protected AlarmService alarmService;

    @Reference(cardinality = ReferenceCardinality.MANDATORY_UNARY)
    protected DeviceService deviceService;


    private final Logger log = LoggerFactory.getLogger(getClass());
    private Set<Alarm> alarms;
    private final AlarmListener alarmListener = new TopoAlarmListenerr();



    @Activate
    protected void activate() {
        log.info("Started");
        alarmService.addListener(alarmListener);
    }

    @Deactivate
    protected void deactivate() {
        //alarmService.removeListener(alarmListener);
        log.info("Stopped");

    }


    //internal alarm listener
    private class TopoAlarmListenerr implements AlarmListener {
        @Override
        public void event(AlarmEvent event) {

            Device localdevice = deviceService.getDevice(event.subject().deviceId());

            if (localdevice.manufacturer().equals("ALTURA") && ( event.subject().description().contains("netconf-config-change") || event.subject().description().contains("netconf-session-start") || event.subject().description().contains("netconf-session-end") )){
                log.info("Se borra alarma {}",event.subject().id());
                try {
                    alarmService.remove(event.subject().id());
                }
                catch (Exception e){
                    log.info("Error al borrar alarma, APP Altura");
                }
            }

            else if (localdevice.manufacturer().equals("ALTURA") && event.subject().description().contains("[--]") && event.subject().description().contains("mux-notify xmlns")) {
                log.info("Se borra alarma {}",event.subject().id());
                try {
                    alarmService.remove(event.subject().id());
                }
                catch (Exception e){
                    log.info("Error al borrar alarma, APP Altura");
                }
            }


        }
    }
}
