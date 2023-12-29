// // Call the dataTables jQuery plugin
// $(document).ready(function() {
//     $('#dataTable').DataTable();
// });


var rootRef = firebase.database().ref().child("Variable");

rootRef.on("child_added", snap => {

    var time = snap.child("time").val();
    var rain_sensor = snap.child("rain_sensor").val();
    var water_sensor_1 = snap.child("water_sensor_1").val();
    var ldr_sensor = snap.child("ldr_sensor").val();
    var water_sensor_2 = snap.child("water_sensor_2").val();
    var temperature_sensor = snap.child("temperature_sensor").val();
    var preasure_sensor = snap.child("preasure_sensor").val();
    var humadity_sensor = snap.child("humadity_sensor").val();
    var motor1 = snap.child("motor1").val();
    var motor2 = snap.child("motor2").val();
    // var time = snap.child("time").val();

    $("#dataTable").append("<tr><td>" + time + "</td><td>" + rain_sensor + "</td><td>" + water_sensor_1 + "</td><td>" + motor1 + "</td><td>" + ldr_sensor +
        "</td><td>" + water_sensor_2 + "</td><td>" + motor2 + "</td><td>" + temperature_sensor +
        "</td><td>" + preasure_sensor + "</td><td>" + humadity_sensor + "</td></tr>");

    setTimeout(function() {
        location.reload();
    }, 17000);
    //\\ $('#dataTable').DataTable("<tr><td>" + name + "</td><td>" + email + "</td><td>" + email + "</td><td>" + name + "</td></tr>");

});