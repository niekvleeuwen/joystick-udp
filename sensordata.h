#ifndef SENSORDATA_H
#define SENSORDATA_H

typedef struct {
        int16_t boardtemp_mv, supplytemp_mv, motorxtemp_mv,
        motorytemp_mv, supplycurr_mv, motors_sto1_mon_mv,
        motors_sto2_mon_mv, motors_supply_mv, motordrive_supply_mv,
        vsupply_mv, fan1_supply_mv, fan2_supply_mv,
        dbg_ref_mv, forcex_return_mv, forcey_return_mv,
        potix_return_mv, potiy_return_mv, ivref_mv,
        ivtemp_mv;
        int16_t boardtemp, supplytemp, motorxtemp,
        motorytemp, supplycurr, motors_sto1_mon,
        motors_sto2_mon, motors_supply, motordrive_supply,
        vsupply, fan1_supply, fan2_supply,
        dbg_ref, forcex_return, forcey_return,
        potix_return, potiy_return, ivref,
        ivtemp;
        uint64_t packets_sent;
} SENSOR_DATA;

typedef struct {
        bool led;
        int32_t force_x, force_y;
} DEBUG_COMMAND;

#endif // SENSORDATA_H
