/**
 * Copyright 2013 Automatak, LLC
 *
 * Licensed to Automatak, LLC (www.automatak.com) under one or more
 * contributor license agreements. See the NOTICE file distributed with this
 * work for additional information regarding copyright ownership. Automatak, LLC
 * licenses this file to you under the Apache License Version 2.0 (the "License");
 * you may not use this file except in compliance with the License. You may obtain
 * a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0.html
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 */
package com.automatak.dnp3.example;

/**
 * Example master than can be run against the example outstation
 */
/*
public class MasterDemo {

    public static void main(String[] args) throws IOException, InterruptedException {

        // create the root class with a thread pool size of 1
        DNP3Manager manager = DNP3ManagerFactory.createManager(1);

        // Create a tcp channel class that will connect to the loopback
        Channel channel = manager.addTCPClient("client", LogLevel.INFO, ChannelRetry.getDefault(), "127.0.0.1", 20000);


        // You can modify the defaults to change the way the master behaves
        MasterStackConfig config = new MasterStackConfig();

        // Create a master instance, pass in a simple singleton to print received values to the console
        Master master = channel.addMaster("master", LogLevel.INTERPRET, PrintingDataObserver.getInstance(), config);

        // You can optionally add a listener to receive state changes on the stack
        master.addStateListener(new StackStateListener() {
            @Override
            public void onStateChange(StackState state) {
                System.out.println("Master state: " + state);
            }
        });

        // This sub-interface can issue command requests
        CommandProcessor processor = master.getCommandProcessor();

        // all this stuff just to read a line of text in Java. Oh the humanity.
        String line = "";
        InputStreamReader converter = new InputStreamReader(System.in);
        BufferedReader in = new BufferedReader(converter);

        while (true) {
            System.out.println("Enter something to issue a command or type <quit> to exit");
            line = in.readLine();
            if(line.equals("quit")) break;
            else {
                ControlRelayOutputBlock crob = new ControlRelayOutputBlock(ControlCode.LATCH_ON, (short) 1, 100, 100, CommandStatus.SUCCESS);
                ListenableFuture<CommandStatus> future = processor.selectAndOperate(crob, 0);
                System.out.println("Control result: " + future.get().name());
            }
        }

        manager.shutdown();
    }
}
*/