var vertex = 
`attribute vec4 a_pos;
void main() 
{ 
    gl_Position = a_pos;
    gl_PointSize = 10.0;
}`; 

var fragment = 
`void main() 
{
    gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
}`;

function main() 
{
  var canvas = document.getElementById('1');
  var gl = canvas.getContext('webgl');
  shader_init(gl, vertex, fragment);

  var a_pos = gl.getAttribLocation(gl.program, 'a_pos'); 
  gl.vertexAttrib3f(a_pos, 0.0, 0.0, 0.0);
  gl.clearColor(0.0, 0.0, 0.0, 1.0); 
  gl.clear(gl.COLOR_BUFFER_BIT); 
  gl.drawArrays(gl.POINTS, 0, 1);
}
