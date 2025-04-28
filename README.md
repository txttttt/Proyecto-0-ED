# coso-ed

BUENAS
## TIPOS DE USUARIO
- "adulto mayor","persona con encesidades especiales","usuario regular","representante organizacional".
- Tiene que tener descripcion y un numero que representa la prioridad a ser atendido, entre menor el numero mayor la priorirdad
- El sistema maneja una lista de tipos de usuarios ordenados segun su prioridad
- por la consulta de estadisticas: tener un contador de tiquetes por cada tipo de usuario.

## SERVICIO
- "comprar boleto", "cambiar boleto", "solicitar informacion", "realizar reclamo" 
- Tiene que tener una descripcion y un numero que representa la prioridad del servicio y el area donde se atienede
- ordenada segun se quiera configurar.
- por la consulta de estadisticas: contador de tiquete por cada servicio disponible.

## AREAS
- secciones donde se atienden los servicios
- el sistema las configura con descripcion, codigo: string que las identifica, y una serie de ventanillas que posee el area
- una cola de prioridad con los tiquetes
- no puede tener una lista de servicios. tiene que jalar de la lista ya existente de servicios.
  
  - ## VENTANILLAS
  - nombre que es el codigo concatenado con un consecutivo. ejemplo C como nombre y 4 ventanillas entonces c1 c2 c3 c4
  - Tiene que tener un espacio para mostrar el codigo del tiquete que se atiende
  - por consulta de estadisticas: contador de cantidad de tiquetes atendidos para cada ventanilla
- por la consulta de estadisticas: tener un contador de tiquetes atendidos

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
- extrae tiquete de la cola prioridad del area al que pertenece ventanilla
- actualiza el codigo del tiquete siendo atendido
- registra la hora en que fue atendido.

## Administracion del sistema
- agregar o eliminar elementos de listas de tipos de usuario, areas disponibles, ventanillas y servicios disponibles.
- Si se borra un tipo de usuario o servicio se eliminan todos los tiquetes.
- Si se borra un area se eliminan todos los servicios y las ventanillas
- Dar un mensaje de advertencia y solicitar confirmacion antes de borrar.

## Consulta de estadisticas
- Tiempo promedio de espera por cada area
  - llevar control del tiempo que toma a cada tiquete en ser atendido y cantidad de tiquetes atendidos en un area.
- Cantidad de tiquetes dispensados por area
  - control de esa info
- Cantidad de tiquetes atendidos por ventanilla
  - para cada ventanilla en especifico
- Cantidad de tiquetes solicitados por servicio
  - para cada servicio en especifico
- Cantidad de tiquetes emitidos por cada tipo de usuario

# ESTRUCTURA SUGERIDA PARA MENU
siempre mostrar las opciones al usuario y cada opcion debe de ser de facil interaccion.
- ## 1. Estado de las colas
   - Muestra areas existentes
   - Cantidad de ventanillas por cada area
   - Codigos de los tiquetes presentes en las colas
   - Cada ventanilla muestra el codigo del ultimo tiquete atendido.
   - opcion para regresar al menu principal
- ## 2. Tiquetes
   - Seleccionar tipo de cliente
     - Muestra la lista de tipos de usuarios para escojer uno sin mostrar las prioridades. Usuario selecciona el tipo de cliente que es
   - Seleccionar tipo de servicio
     - Muestra la lista de servicios, el orden de esta lista no debe ser fija ni por areas, se configura en el sistema.
     - Usuario seleciona un servicio y el sistema genera el tiquete y lo inserta en la cola de prioridad respectiva
     - Imprime todos los datos del tiquete
     - Se mantiene en el menu de tiquetes al hacer esta accion
   - Regresar a menu
- ## 3. Atender
  - Solicita al usuario area y numero de ventanilla
  - busca en la cola respectiva el siguiente en ser atendido, lo elimina de la cola y lo asigna como tiquete que se esta atendiendo.
  - Actualiza los datos necesario para que se refleje en las estadisticas.
  - Si no hay ningun elemento en la cola debe indicar que no hay usuarios en espera, luego de realizar la accion regresa al menu principal.
- ## 4. Administracion
  - ### Tipos de usuario
    - Agregar
      - agrega un tipo de usuario con su nombre y prioridad a la lista de tipos de usuario del sistema, ordena la lista segun priordad.
      - Luego de realizar la accion se mantiene en el menu de tipos de usuario.
    - Eliminar
      - Elimina un tipo de usuario del sistema. luego de realizar la accion se mantiene en el menu de tipos de usuario.
    - Regresar
      - regresa al menu de administracion
  - ### Servicios disponibles
    - Agregar
      - agrega un nuevo servicio con su descripcion, area de atencion y prioridad
      - se mantiene en el menu de servicios disponibles luego de hacer la accion
    - Eliminar
      - Muestra la lista de servicios disponibles y elige uno para eliminarlo
      - Deben borrarse todos los tiquetes de las cosas de todas las areas.
      - Luego de realizar la accion se mantiene en el menu de servicios disponinbles.
    - Reordenar
      - Permite al usuario reordenar los elementos en la lista de servicios. Solicita el numero de servicio a reubicar y la posicion destino.
      - Solo hay una lista de servicios y no se debe de aprupar por area ni por otro criterio.
      - Luego de realizar la accion se mantiene en el menu de servicios disponibles.
    - Regresar
      - regresa al menu de administracion.
      - 
