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

## TIQUETE  
- codigo: codigo del area y un consecutivo global, consecutivo empieza en 100. NUNCA se genera uno con un diferente numero de area y mismo consecutivo
- Hora en que fueron solicitados, tiempo de espera para ser atendidos se calcula luego.
- Prioridad final: PrioridadTiquete = PrioridadUsuario * 10 + PrioridadServicio
