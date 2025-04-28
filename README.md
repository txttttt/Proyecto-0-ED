# coso-ed

BUENAS
## TIPOS DE USUARIO
- "adulto mayor","persona con encesidades especiales","usuario regular","representante organizacional".
- Tiene que tener descripcion y un numero que representa la prioridad a ser atendido, entre menor el numero mayor la priorirdad
- El sistema maneja una lista de tipos de usuarios ordenados segun su prioridad

## SERVICIO
- "comprar boleto", "cambiar boleto", "solicitar informacion", "realizar reclamo" 
- Tiene que tener una descripcion y un numero que representa la prioridad del servicio y el area donde se atienede
- ordenada segun se quiera configurar.

## AREAS
- secciones donde se atienden los servicios
- el sistema las configura con descripcion, codigo: string que las identifica, y una serie de ventanillas que posee el area
- una cola de prioridad con los tiquetes
  - VENTANILLAS
  - nombre que es el codigo concatenado con un consecutivo. ejemplo C como nombre y 4 ventanillas entonces c1 c2 c3 c4
  - Tiene que tener un espacio para mostrar el codigo del tiquete que se atiende
-por la consulta de estadisticas: tener un contador de tiquetes atendidos

## TIQUETE  
- codigo: codigo del area y un consecutivo global, consecutivo empieza en 100. NUNCA se genera uno con un diferente numero de area y mismo consecutivo
- Hora en que fueron solicitados, tiempo de espera para ser atendidos se calcula luego.
- Prioridad final: PrioridadTiquete = PrioridadUsuario * 10 + PrioridadServicio

# FUNCIONALIDADES DEL SISTEMA
## Solicitud de un tiquete
- selecciona tipo de usuario
- servicio a usar
- genera tiquete con el codigo
- hora actual
- prioridad final 
- se inserta en la cola prioridad del area

## Ventanilla atiene tiquete
- ingresa el codigo de la ventanilla que atiende el tiquete
- extrae tiquete del area al que pertenece ventanilla
- actualiza el codigo siendo atendido
- registra la hora en que fue atendido.

## Administracion del sistema
- agregar o eliminar elementos de listas de tipos de usuario, areas disponibles, ventanillas y servicios disponibles.
- Si se borra un tipo de usuario o servicio se eliminan todos los tiquetes.
- Si se borra un area se eliminan todos los servicios y las ventanillas
- Dar un mensaje de advertencia y solicitar confirmacion antes de borrar.

## Consulta de estadisticas
- Tiempo promedio de espera por cada area
  - llevar control del tiempo que toma a cada tiquete en ser atendido y cantidad de tiquetes atendidos en un area.
