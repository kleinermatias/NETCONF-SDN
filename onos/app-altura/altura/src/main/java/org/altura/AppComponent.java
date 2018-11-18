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


    private final Logger log = LoggerFactory.getLogger(getClass());
    private Set<Alarm> alarms;

    @Activate
    protected void activate() {
        log.info("Started");
        getAlarms();
    }

    @Deactivate
    protected void deactivate() {
        log.info("Stopped");
    }


    private void getAlarms() {

        alarms = alarmService.getActiveAlarms();

        printAlarms(alarms);
        log.info("PRINT DE ALARMAS");
    }

    void printAlarms(Set<Alarm> alarms) {
        //FIXME this can be better formatted
        alarms.forEach((alarm) -> {
            log.info(ToStringBuilder.reflectionToString(alarm, ToStringStyle.SHORT_PREFIX_STYLE));
        });
    }
}