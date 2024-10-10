# Actividad 8 - Primeros pasos con K8s

Para esta actividad de instalar un ambiente local se utilizara Minikube para instalar un cluster de Kubernetes local y se desplegará una aplicación de ejemplo.

## Instalación de Minikube
Se trabajo en un entorno x86-64 linux (Ubunutu), por lo que se utilizo el siguiente comando para instalar Minikube:

De la documentación oficial de [Minikube](https://minikube.sigs.k8s.io/docs/start/?arch=%2Flinux%2Fx86-64%2Fstable%2Fbinary+download) se puede ver que se puede instalar con el siguiente comando:
```bash
curl -LO https://storage.googleapis.com/minikube/releases/latest/minikube-linux-amd64
sudo install minikube-linux-amd64 /usr/local/bin/minikube && rm minikube-linux-amd64
```

## Iniciar Minikube
Para iniciar Minikube se utilizo el siguiente comando:
```bash
minikube start
```

## Desplegar una aplicación de ejemplo
En la carpeta actividades se encuentra un archivo llamado [deployment.yaml](/actividad8/deployment.yaml) que contiene la configuración para desplegar una aplicación de ejemplo en un cluster de Kubernetes, donde se especifica que se desplegará un deployment llamado `webservice` con un contenedor llamado `webservice` que utiliza la imagen `nginx` y se expone en el puerto 80.

Para desplegar una aplicación de ejemplo se utilizo el siguiente comando:
```bash
 kubectl apply -f deployment.yaml
```
Para poder vel el despliegue se utilizo el siguiente comando:
```bash
kubectl get pods
```

Y para poder ver la aplicación en el puerto 8000 del localhost se utilizo el comando.
```bash
kubectl port-forward pods/webservice-649bffc7b8-8gcm2 8000:80 -n default
```
![nginx](/actividad8/img/nginx.png)

## Detener Minikube
Para detener Minikube y que no consuma recursos se utilizo el siguiente comando:
```bash
minikube stop
```

# Pregunta

### ¿En un ambiente local de Kubernetes existen los nodos masters y workers, como es que esto funciona?

En un entorno local como Minikube, no se maneja la misma arquitectura que en un ambiente de producción, en Minikube solo se tiene un nodo que actua como master y worker, por lo que no se tiene una separación de nodos master y worker, ya que solo se tiene un nodo que actua como ambos.
Y como es que esto funciona?
Pues cuando uno ejecuta el comando `minikube start` se crea un cluster de Kubernetes local donde:
- El nodo master y los nodos worker están integrados en esa misma instancia.
- El nodo master maneja la coordinación del clúster, como el API Server, el scheduler y etcd.
- El mismo nodo también actúa como worker, ejecutando los pods y las aplicaciones.

