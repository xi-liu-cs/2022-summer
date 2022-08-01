vertex = 
`attribute vec4 a_Position;
attribute float a_PointSize;
void main() 
{ 
    gl_Position = a_Position;
    gl_PointSize = a_PointSize;
}`; 

fragment = 
`void main() 
{
    gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
}`;

function main() 
{
  canvas = document.getElementById('1');
  gl = canvas.getContext('webgl');
  shader_init(gl, vertex, fragment);

  a_Position = gl.getAttribLocation(gl.program, 'a_Position'); 
  a_PointSize = gl.getAttribLocation(gl.program, 'a_PointSize');
  gl.vertexAttrib3f(a_Position, 0.0, 0.0, 0.0);
  gl.vertexAttrib1f(a_PointSize, 10.0);
  
  gl.clearColor(0.0, 0.0, 0.0, 1.0); 
  gl.clear(gl.COLOR_BUFFER_BIT); 
  gl.drawArrays(gl.POINTS, 0, 1);
}
