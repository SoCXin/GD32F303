/*!
    \file  gd32f30x_it.c
    \brief interrupt service routines
    
    \version 2017-02-10, V1.0.0, firmware for GD32F30x
    \version 2018-10-10, V1.1.0, firmware for GD32F30x
    \version 2018-12-25, V2.0.0, firmware for GD32F30x
*/

/*
    Copyright (c) 2018, GigaDevice Semiconductor Inc.

    All rights reserved.

    Redistribution and use in source and binary forms, with or without modification, 
are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this 
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice, 
       this list of conditions and the following disclaimer in the documentation 
       and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors 
       may be used to endorse or promote products derived from this software without 
       specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
OF SUCH DAMAGE.
*/

#include "gd32f30x_it.h"

extern ErrStatus test_flag_interrupt;

/*!
    \brief      this function handles NMI exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void NMI_Handler(void)
{
}

/*!
    \brief      this function handles HardFault exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void HardFault_Handler(void)
{
    /* if Hard Fault exception occurs, go to infinite loop */
    while(1){
    }
}

/*!
    \brief      this function handles MemManage exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void MemManage_Handler(void)
{
    /* if Memory Manage exception occurs, go to infinite loop */
    while(1){
    }
}

/*!
    \brief      this function handles BusFault exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void BusFault_Handler(void)
{
    /* if Bus Fault exception occurs, go to infinite loop */
    while(1){
    }
}

/*!
    \brief      this function handles UsageFault exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void UsageFault_Handler(void)
{
    /* if Usage Fault exception occurs, go to infinite loop */
    while(1){
    }
}

/*!
    \brief      this function handles SVC exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void SVC_Handler(void)
{
}

/*!
    \brief      this function handles DebugMon exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void DebugMon_Handler(void)
{
}

/*!
    \brief      this function handles PendSV exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void PendSV_Handler(void)
{
}

/*!
    \brief      this function handles SysTick exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void SysTick_Handler(void)
{
}

/*!
    \brief      this function handles CAN0 RX1 exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void CAN0_RX1_IRQHandler(void)
{
    can_receive_message_struct receive_message;
    /* initialize receive message */
    receive_message.rx_sfid = 0x00;
    receive_message.rx_efid = 0x00;
    receive_message.rx_ff = 0;
    receive_message.rx_dlen = 0;
    receive_message.rx_fi = 0;
    receive_message.rx_data[0] = 0x00;
    receive_message.rx_data[1] = 0x00;
    
    /* check the receive message */
    can_message_receive(CAN0, CAN_FIFO1, &receive_message);
    
    if((0x1234 == receive_message.rx_efid) && (CAN_FF_EXTENDED == receive_message.rx_ff)
        && (2 == receive_message.rx_dlen) && (0xCADE == (receive_message.rx_data[1]<<8|receive_message.rx_data[0]))){
        test_flag_interrupt = SUCCESS; 
    }else{
        test_flag_interrupt = ERROR; 
    }
}

/*!
    \brief      this function handles CAN1 RX0 exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void CAN1_RX1_IRQHandler(void)
{
    can_receive_message_struct receive_message;
    /* initialize receive message */
    receive_message.rx_sfid = 0x00;
    receive_message.rx_efid = 0x00;
    receive_message.rx_ff = 0;
    receive_message.rx_dlen = 0;
    receive_message.rx_fi = 0;
    receive_message.rx_data[0] = 0x00;
    receive_message.rx_data[1] = 0x00;

    /* check the receive message */
    can_message_receive(CAN1, CAN_FIFO1, &receive_message);

    if((0x1234 == receive_message.rx_efid) && (CAN_FF_EXTENDED == receive_message.rx_ff)
        && (2 == receive_message.rx_dlen) && (0xCADE == (receive_message.rx_data[1]<<8|receive_message.rx_data[0]))){
        test_flag_interrupt = SUCCESS; 
    }else{
        test_flag_interrupt = ERROR; 
    }
}