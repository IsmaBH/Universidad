/*
 *  MIT License
 *
 *  Copyright (c) 2019 Michael Pogrebinsky - Distributed Systems & Cloud Computing with Java
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

package com.mycompany.clientezookeepereleccion;

import org.apache.zookeeper.*;
import java.io.IOException;

import java.io.IOException;
import java.util.Collections;
import java.util.List;

public class ClienteZookeeperEleccion implements Watcher {

    private static final String ZOOKEEPER_ADDRESS = "localhost:2181";
    private static final int SESSION_TIMEOUT = 3000;
    private static final String ELECTION_NAMESPACE = "/eleccion";
    private String currentZnodeName;
    private ZooKeeper zooKeeper;

    public static void main(String[] arg) throws IOException, InterruptedException, KeeperException {
        ClienteZookeeperEleccion clienteBasico = new ClienteZookeeperEleccion();
        clienteBasico.connectToZookeeper();
        
        clienteBasico.voluntarioParaLiderazgo();
        clienteBasico.liderElecto();
        
        clienteBasico.run();
        clienteBasico.close();
        System.out.println("Desconectado del servidor Zookeeper. Terminando la aplicaciÃ³n cliente.");
    }

    public void connectToZookeeper() throws IOException {
        this.zooKeeper = new ZooKeeper(ZOOKEEPER_ADDRESS, SESSION_TIMEOUT, this);
    }

    private void run() throws InterruptedException {
        synchronized (zooKeeper) {
            zooKeeper.wait();
        }
    }

    private void close() throws InterruptedException {
        this.zooKeeper.close();
    }

    @Override
    public void process(WatchedEvent event) {
        switch (event.getType()) {
            case None:
                if (event.getState() == Event.KeeperState.SyncConnected) {
                    System.out.println("Conectado exitosamente a Zookeeper");
                } else {
                    synchronized (zooKeeper) {
                        System.out.println("Desconectando de Zookeeper...");
                        zooKeeper.notifyAll();
                    }
                }
        }
    }
    /*
    * El metodo voluntarioParaLiderazgo permite añadir un nuevo nodo z que sea elegible
    * para ser un nuevo lider en caso de ser requerido.
    */
    public void voluntarioParaLiderazgo() throws KeeperException, InterruptedException {
        //znodePrefix guardara el nombre del nodo salvo su numero identificador
        String znodePrefix = ELECTION_NAMESPACE + "/c_";
        //Crea un nodo z en el path del primer argumento
        String znodeFullPath = zooKeeper.create(znodePrefix, new byte[]{},ZooDefs.Ids.OPEN_ACL_UNSAFE, CreateMode.EPHEMERAL_SEQUENTIAL);       
        //Imprime el nombre del znode creado
        System.out.println("Nombre del znode: " + znodeFullPath);

        this.currentZnodeName = znodeFullPath.replace("/eleccion/", "");
    }
    
    public void liderElecto() throws KeeperException, InterruptedException {

       List<String> children = zooKeeper.getChildren(ELECTION_NAMESPACE, false);

       Collections.sort(children);

       String smallestChild = children.get(0);

 

       if (smallestChild.equals(currentZnodeName)) {

          System.out.println("Yo soy el lider");

          return;

       }

       System.out.println("Yo no soy el lider, " + smallestChild + " es el lider");

    }
}