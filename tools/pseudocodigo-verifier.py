RUTA_TXT = "./pseudocodigo_boceto.txt"
CONDICIONALES = ["- Mientras", "- Para", "- Si"]
COMPARATIVOS = ["!=",">=", "<="]

def cambiarAsignacionesPorLinea(linea: str):
    if any(condicional in linea for condicional in CONDICIONALES):
        nuevaLinea = linea.replace("<-","=")
    if any(comparativo in linea for comparativo in COMPARATIVOS):
        return linea
    if "==" in linea:
        nuevaLinea = linea.replace("==","=")
    else:
        nuevaLinea = linea.replace("=","<-")
    return nuevaLinea

def corregirPara(linea:str):
    if "- Para i ->" in linea:
        nuevaLinea = linea.replace("- Para i ->","- Para i <-")
        return nuevaLinea
    else:
        return linea

def colocarEspacioEntreFunciones(linea:str):
    if linea[0] == "-" and "(" in linea and "main" not in linea:
        nuevaLinea = '\n\n' + linea
    else:
        nuevaLinea = linea
    return nuevaLinea

def corregirTxt(ruta:str):
    txt = open(ruta, "r+")
    lineas = txt.readlines()
    
    lineas_corregidas = []
    
    for linea in lineas:
        nuevaLinea = cambiarAsignacionesPorLinea(linea)
        nuevaLinea = corregirPara(nuevaLinea)
        nuevaLinea = colocarEspacioEntreFunciones(nuevaLinea)
        print(nuevaLinea)
        lineas_corregidas.append(nuevaLinea)
        
    txt.seek(0)
    txt.writelines(lineas_corregidas)
    txt.truncate()
    
    txt.close()

corregirTxt(RUTA_TXT)