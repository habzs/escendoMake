const rootRef = db.ref('vacant');

var oneBox = document.getElementById("one");
var twoBox = document.getElementById("two");
var threeBox = document.getElementById("three");
var occupancySpan = document.getElementById("counter");

var currentStateOne = 0
var currentStateTwo = 0
var currentStateThree = 0

var occupancy = 0;

// function addData() {
//     writeUserData();
//     console.log("ua");

// }

// function addData() {
//     console.log("Changed");
//     // rootRef.child("one").set({
//     //     state: "true"
//     // });

//     var nowie = moment().format();

//     const newData = {
//         state: "false",
//         time: nowie,
//     };

//     const updates = {};
//     updates['/vacant/' + "one"] = newData;
//     db.ref().update(updates);

// }


// db.ref("/vacant/one")
rootRef.on('value', (snapshot) => {
    const data = snapshot.val();
    // console.log("data: ", data.one.status);
    // console.log("two: ", snapshot.val().two.status);
    // console.log("five: ", data[1].name);
    // console.log(typeof (data));

    updateColors(data);
})



function updateColors(data) {
    var occupancy = 0;
    var plural;

    if (data.one.status === 1) {
        oneBox.setAttribute("class", "btn btn-danger");
    } else {
        oneBox.setAttribute("class", "btn btn-success");
    }

    if (data.two.status === 1) {
        twoBox.setAttribute("class", "btn btn-danger");
    } else {
        twoBox.setAttribute("class", "btn btn-success");
    }

    if (data.three.status === 1) {
        threeBox.setAttribute("class", "btn btn-danger");
    } else {
        threeBox.setAttribute("class", "btn btn-success");
    }


    for (key in data) {
        if (data[key].status === 1) {
            occupancy++;
        }

    }

    if (occupancy === 1) {
        plural = "table occupied.";
    } else {
        plural = "tables occupied.";
    }

    occupancySpan.innerHTML = `${occupancy} ${plural}`
}


