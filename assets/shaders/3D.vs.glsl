#version 330 core

// Attributs de sommet
layout(location = 0) in vec2 aVertexPosition;
//layout(location = 1) in vec3 aVertexNormal;
layout(location = 2) in vec2 aVertexTexCoords;

// Matrices de transformations reçues en uniform
uniform mat4 uMVPMatrix;
uniform mat4 uMVMatrix;
uniform mat4 uNormalMatrix;

// Sorties du shader
out vec3 vPosition_vs;
//out vec3 vNormal_vs;
out vec2 vTexCoords;

void main() {

  // Passage en coordonnées homogènes
  vec4 vertexPosition = vec4(aVertexPosition, 0, 1);
  // vec4 vertexNormal = vec4(aVertexNormal, 0);

  // Calcul des valeurs de sortie
  // vPosition_vs = vec3(uMVMatrix * vertexPosition);
  // vNormal_vs = vec3(uNormalMatrix * vertexNormal);
  // vTexCoords = aVertexTexCoords;

  // Calcul de la position projetée
     gl_Position = uMVPMatrix * vertexPosition;
  // gl_Position = vec4(aVertexPosition, 0, 1);

  vPosition_vs = vec3 (aVertexPosition,1);
  //vNormal_vs = aVertexNormal;
  vTexCoords = aVertexTexCoords;
}
